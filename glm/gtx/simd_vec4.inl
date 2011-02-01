///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2011 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2009-05-07
// Updated : 2009-05-07
// Licence : This source is under MIT License
// File    : glm/gtx/simd_vec4.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glm
{
	namespace detail
	{
		template <int Value>
		struct mask
		{
			enum{value = Value};
		};

		//////////////////////////////////////
		// Implicit basic constructors

		inline fvec4SIMD::fvec4SIMD()
		{}

		inline fvec4SIMD::fvec4SIMD(__m128 const & Data) :
			Data(Data)
		{}

		inline fvec4SIMD::fvec4SIMD(fvec4SIMD const & v) :
			Data(v.Data)
		{}

		inline fvec4SIMD::fvec4SIMD(tvec4<float> const & v) :
			Data(_mm_set_ps(v.w, v.z, v.y, v.x))
		{}

		//////////////////////////////////////
		// Explicit basic constructors

		inline fvec4SIMD::fvec4SIMD(float const & s) :
			Data(_mm_set1_ps(s))
		{}

		inline fvec4SIMD::fvec4SIMD(float const & x, float const & y, float const & z, float const & w) :
	//		Data(_mm_setr_ps(x, y, z, w))
			Data(_mm_set_ps(w, z, y, x))
		{}
/*
		inline fvec4SIMD::fvec4SIMD(float const v[4]) :
			Data(_mm_load_ps(v))
		{}
*/
		//////////////////////////////////////
		// Swizzle constructors

		//fvec4SIMD(ref4<float> const & r);

		//////////////////////////////////////
		// Convertion vector constructors

		inline fvec4SIMD::fvec4SIMD(vec2 const & v, float const & s1, float const & s2) :
			Data(_mm_set_ps(s2, s1, v.y, v.x))
		{}

		inline fvec4SIMD::fvec4SIMD(float const & s1, vec2 const & v, float const & s2) :
			Data(_mm_set_ps(s2, v.y, v.x, s1))
		{}

		inline fvec4SIMD::fvec4SIMD(float const & s1, float const & s2, vec2 const & v) :
			Data(_mm_set_ps(v.y, v.x, s2, s1))
		{}

		inline fvec4SIMD::fvec4SIMD(vec3 const & v, float const & s) :
			Data(_mm_set_ps(s, v.z, v.y, v.x))
		{}

		inline fvec4SIMD::fvec4SIMD(float const & s, vec3 const & v) :
			Data(_mm_set_ps(v.z, v.y, v.x, s))
		{}

		inline fvec4SIMD::fvec4SIMD(vec2 const & v1, vec2 const & v2) :
			Data(_mm_set_ps(v2.y, v2.x, v1.y, v1.x))
		{}

		//inline fvec4SIMD::fvec4SIMD(ivec4SIMD const & v) :
		//	Data(_mm_cvtepi32_ps(v.Data))
		//{}

		//////////////////////////////////////
		// Unary arithmetic operators

		inline fvec4SIMD& fvec4SIMD::operator=(fvec4SIMD const & v)
		{
			this->Data = v.Data;
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator+=(float const & s)
		{
			this->Data = _mm_add_ps(Data, _mm_set_ps1(s));
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator+=(fvec4SIMD const & v)
		{
			this->Data = _mm_add_ps(this->Data , v.Data);
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator-=(float const & s)
		{
			this->Data = _mm_sub_ps(Data, _mm_set_ps1(s));
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator-=(fvec4SIMD const & v)
		{
			this->Data = _mm_sub_ps(this->Data , v.Data);
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator*=(float const & s)
		{
			this->Data = _mm_mul_ps(this->Data, _mm_set_ps1(s));
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator*=(fvec4SIMD const & v)
		{
			this->Data = _mm_mul_ps(this->Data , v.Data);
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator/=(float const & s)
		{
			this->Data = _mm_div_ps(Data, _mm_set1_ps(s));
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator/=(fvec4SIMD const & v)
		{
			this->Data = _mm_div_ps(this->Data , v.Data);
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator++()
		{
			this->Data = _mm_add_ps(this->Data , glm::detail::one);
			return *this;
		}

		inline fvec4SIMD& fvec4SIMD::operator--()
		{
			this->Data = _mm_sub_ps(this->Data, glm::detail::one);
			return *this;
		}

		//////////////////////////////////////
		// Swizzle operators

		template <comp X, comp Y, comp Z, comp W>
		inline fvec4SIMD fvec4SIMD::swizzle() const
		{
			__m128 Data = _mm_shuffle_ps(
				this->Data, this->Data, 
				mask<(W << 6) | (Z << 4) | (Y << 2) | (X << 0)>::value);
			return fvec4SIMD(Data);
		}

		template <comp X, comp Y, comp Z, comp W>
		inline fvec4SIMD& fvec4SIMD::swizzle()
		{
			this->Data = _mm_shuffle_ps(
				this->Data, this->Data, 
				mask<(W << 6) | (Z << 4) | (Y << 2) | (X << 0)>::value);
			return *this;
		}

		// operator+
		inline fvec4SIMD operator+ (fvec4SIMD const & v, float s)
		{
			return fvec4SIMD(_mm_add_ps(v.Data, _mm_set1_ps(s)));
		}

		inline fvec4SIMD operator+ (float s, fvec4SIMD const & v)
		{
			return fvec4SIMD(_mm_add_ps(_mm_set1_ps(s), v.Data));
		}

		inline fvec4SIMD operator+ (fvec4SIMD const & v1, fvec4SIMD const & v2)
		{
			return fvec4SIMD(_mm_add_ps(v1.Data, v2.Data));
		}

		//operator-
		inline fvec4SIMD operator- (fvec4SIMD const & v, float s)
		{
			return fvec4SIMD(_mm_sub_ps(v.Data, _mm_set1_ps(s)));
		}

		inline fvec4SIMD operator- (float s, fvec4SIMD const & v)
		{
			return fvec4SIMD(_mm_sub_ps(_mm_set1_ps(s), v.Data));
		}

		inline fvec4SIMD operator- (fvec4SIMD const & v1, fvec4SIMD const & v2)
		{
			return fvec4SIMD(_mm_sub_ps(v1.Data, v2.Data));
		}

		//operator*
		inline fvec4SIMD operator* (fvec4SIMD const & v, float s)
		{
			__m128 par0 = v.Data;
			__m128 par1 = _mm_set1_ps(s);
			return fvec4SIMD(_mm_mul_ps(par0, par1));
		}

		inline fvec4SIMD operator* (float s, fvec4SIMD const & v)
		{
			__m128 par0 = _mm_set1_ps(s);
			__m128 par1 = v.Data;
			return fvec4SIMD(_mm_mul_ps(par0, par1));
		}

		inline fvec4SIMD operator* (fvec4SIMD const & v1, fvec4SIMD const & v2)
		{
			return fvec4SIMD(_mm_mul_ps(v1.Data, v2.Data));
		}

		//operator/
		inline fvec4SIMD operator/ (fvec4SIMD const & v, float s)
		{
			__m128 par0 = v.Data;
			__m128 par1 = _mm_set1_ps(s);
			return fvec4SIMD(_mm_div_ps(par0, par1));
		}

		inline fvec4SIMD operator/ (float s, fvec4SIMD const & v)
		{
			__m128 par0 = _mm_set1_ps(s);
			__m128 par1 = v.Data;
			return fvec4SIMD(_mm_div_ps(par0, par1));
		}

		inline fvec4SIMD operator/ (fvec4SIMD const & v1, fvec4SIMD const & v2)
		{
			return fvec4SIMD(_mm_div_ps(v1.Data, v2.Data));
		}

		// Unary constant operators
		inline fvec4SIMD operator- (fvec4SIMD const & v)
		{
			return fvec4SIMD(_mm_sub_ps(_mm_setzero_ps(), v.Data));
		}

		inline fvec4SIMD operator++ (fvec4SIMD const & v, int)
		{
			return fvec4SIMD(_mm_add_ps(v.Data, glm::detail::one));
		}

		inline fvec4SIMD operator-- (fvec4SIMD const & v, int)
		{
			return fvec4SIMD(_mm_sub_ps(v.Data, glm::detail::one));
		}

	}//namespace detail

	namespace gtx{
	namespace simd_vec4
	{
		inline detail::tvec4<float> vec4_cast
		(
			detail::fvec4SIMD const & x
		)
		{
			detail::tvec4<float> Result;
			_mm_store_ps(&Result[0], x.Data);
			return Result;
		}

		// Other possible implementation
		//float abs(float a)
		//{
		//  return max(-a, a);
		//}
		detail::fvec4SIMD abs
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_abs_ps(x.Data);
		}

		inline detail::fvec4SIMD sign
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_sgn_ps(x.Data);
		}

		inline detail::fvec4SIMD floor
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_flr_ps(x.Data);
		}

		inline detail::fvec4SIMD trunc
		(
			detail::fvec4SIMD const & x
		)
		{
			__m128 Flr0 = detail::sse_flr_ps(_mm_sub_ps(_mm_setzero_ps(), x.Data));
			__m128 Sub0 = _mm_sub_ps(Flr0, x.Data);
			__m128 Flr1 = detail::sse_flr_ps(x.Data);

			__m128 Cmp0 = _mm_cmplt_ps(x.Data, glm::detail::zero);
			__m128 Cmp1 = _mm_cmpnlt_ps(x.Data, glm::detail::zero);

			__m128 And0 = _mm_and_ps(Flr0, Cmp0);
			__m128 And1 = _mm_and_ps(Flr1, Cmp1);

			return _mm_or_ps(And0, And1);
		}

		inline detail::fvec4SIMD round
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_rnd_ps(x.Data);
		}

		//inline detail::fvec4SIMD roundEven
		//(
		//	detail::fvec4SIMD const & x
		//)
		//{

		//}

		inline detail::fvec4SIMD ceil
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_ceil_ps(x.Data);
		}

		inline detail::fvec4SIMD fract
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_frc_ps(x.Data);
		}

		inline detail::fvec4SIMD mod
		(
			detail::fvec4SIMD const & x, 
			detail::fvec4SIMD const & y
		)
		{
			return detail::sse_mod_ps(x.Data, y.Data);
		}

		inline detail::fvec4SIMD mod
		(
			detail::fvec4SIMD const & x, 
			float const & y
		)
		{
			return detail::sse_mod_ps(x.Data, _mm_set1_ps(y));
		}

		//inline detail::fvec4SIMD modf
		//(
		//	detail::fvec4SIMD const & x, 
		//	detail::fvec4SIMD & i
		//)
		//{

		//}

		inline detail::fvec4SIMD min
		(
			detail::fvec4SIMD const & x, 
			detail::fvec4SIMD const & y
		)
		{
			return _mm_min_ps(x.Data, y.Data);
		}

		inline detail::fvec4SIMD min
		(
			detail::fvec4SIMD const & x, 
			float const & y
		)
		{
			return _mm_min_ps(x.Data, _mm_set1_ps(y));
		}

		inline detail::fvec4SIMD max
		(
			detail::fvec4SIMD const & x, 
			detail::fvec4SIMD const & y
		)
		{
			return _mm_max_ps(x.Data, y.Data);
		}

		inline detail::fvec4SIMD max
		(
			detail::fvec4SIMD const & x, 
			float const & y
		)
		{
			return _mm_max_ps(x.Data, _mm_set1_ps(y));
		}

		inline detail::fvec4SIMD clamp
		(
			detail::fvec4SIMD const & x, 
			detail::fvec4SIMD const & minVal, 
			detail::fvec4SIMD const & maxVal
		)
		{
			return detail::sse_clp_ps(x.Data, minVal.Data, maxVal.Data);
		}

		inline detail::fvec4SIMD clamp
		(
			detail::fvec4SIMD const & x, 
			float const & minVal, 
			float const & maxVal
		) 
		{
			return detail::sse_clp_ps(x.Data, _mm_set1_ps(minVal), _mm_set1_ps(maxVal));
		}

		inline detail::fvec4SIMD mix
		(
			detail::fvec4SIMD const & x, 
			detail::fvec4SIMD const & y, 
			detail::fvec4SIMD const & a
		)
		{
			__m128 Sub0 = _mm_sub_ps(y.Data, x.Data);
			__m128 Mul0 = _mm_mul_ps(a.Data, Sub0);
			return _mm_mul_ps(x.Data, Mul0);
		}

		inline detail::fvec4SIMD step
		(
			detail::fvec4SIMD const & edge, 
			detail::fvec4SIMD const & x
		)
		{
			__m128 cmp0 = _mm_cmpngt_ps(x.Data, edge.Data);
			return _mm_max_ps(_mm_min_ps(cmp0, _mm_setzero_ps()), detail::one);
		}

		inline detail::fvec4SIMD step
		(
			float const & edge, 
			detail::fvec4SIMD const & x
		)
		{
			__m128 cmp0 = _mm_cmpngt_ps(x.Data, _mm_set1_ps(edge));
			return _mm_max_ps(_mm_min_ps(cmp0, _mm_setzero_ps()), detail::one);
		}

		inline detail::fvec4SIMD smoothstep
		(
			detail::fvec4SIMD const & edge0, 
			detail::fvec4SIMD const & edge1, 
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_ssp_ps(edge0.Data, edge1.Data, x.Data);
		}

		inline detail::fvec4SIMD smoothstep
		(
			float const & edge0, 
			float const & edge1, 
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_ssp_ps(_mm_set1_ps(edge0), _mm_set1_ps(edge1), x.Data);
		}

		//inline bvec4 isnan(detail::fvec4SIMD const & x)
		//{

		//}

		//inline bvec4 isinf(detail::fvec4SIMD const & x)
		//{

		//}

		//inline detail::ivec4SIMD floatBitsToInt
		//(
		//	detail::fvec4SIMD const & value
		//)
		//{

		//}

		//inline detail::fvec4SIMD intBitsToFloat
		//(
		//	detail::ivec4SIMD const & value
		//)
		//{

		//}

		inline detail::fvec4SIMD fma
		(
			detail::fvec4SIMD const & a, 
			detail::fvec4SIMD const & b, 
			detail::fvec4SIMD const & c
		)
		{
			return _mm_add_ps(_mm_mul_ps(a.Data, b.Data), c.Data);
		}

		inline float simdLength
		(
			detail::fvec4SIMD const & x
		)
		{
			float Result = 0;
			_mm_store_ss(&Result, detail::sse_len_ps(x.Data));
			return Result;
		}

		inline detail::fvec4SIMD simdLength4
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_len_ps(x.Data);
		}

		inline float simdDistance
		(
			detail::fvec4SIMD const & p0,
			detail::fvec4SIMD const & p1
		)
		{
			float Result = 0;
			_mm_store_ss(&Result, detail::sse_dst_ps(p0.Data, p1.Data));
			return Result;
		}

		inline detail::fvec4SIMD simdDistance4
		(
			detail::fvec4SIMD const & p0,
			detail::fvec4SIMD const & p1
		)
		{
			return detail::sse_dst_ps(p0.Data, p1.Data);
		}

		inline float simdDot
		(
			detail::fvec4SIMD const & x,
			detail::fvec4SIMD const & y
		)
		{
			float Result = 0;
			_mm_store_ss(&Result, detail::sse_dot_ss(x.Data, y.Data));
			return Result;
		}

		inline detail::fvec4SIMD simdDot4
		(
			detail::fvec4SIMD const & x,
			detail::fvec4SIMD const & y
		)
		{
			return detail::sse_dot_ss(x.Data, y.Data);
		}

		inline detail::fvec4SIMD simdCross
		(
			detail::fvec4SIMD const & x,
			detail::fvec4SIMD const & y
		)
		{
			return detail::sse_xpd_ps(x.Data, y.Data);
		}

		inline detail::fvec4SIMD simdNormalize
		(
			detail::fvec4SIMD const & x
		)
		{
			return detail::sse_nrm_ps(x.Data);
		}

		inline detail::fvec4SIMD simdFaceforward
		(
			detail::fvec4SIMD const & N,
			detail::fvec4SIMD const & I,
			detail::fvec4SIMD const & Nref
		)
		{
			return detail::sse_ffd_ps(N.Data, I.Data, Nref.Data);
		}

		inline detail::fvec4SIMD simdReflect
		(
			detail::fvec4SIMD const & I,
			detail::fvec4SIMD const & N
		)
		{
			return detail::sse_rfe_ps(I.Data, N.Data);
		}

		inline detail::fvec4SIMD simdRefract
		(
			detail::fvec4SIMD const & I,
			detail::fvec4SIMD const & N,
			float const & eta
		)
		{
			return detail::sse_rfa_ps(I.Data, N.Data, _mm_set1_ps(eta));
		}

	}//namespace simd_vec4
	}//namespace gtx
}//namespace glm