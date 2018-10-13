#include <vector>  // std::vector
#include <complex> // std::complex

using base_t  = std::complex<double>;
using vCoef_t = std::vector<base_t>;

//====================================================================================================================================
//!
//! \brief   Evaluates the value of a polynomial at a point using the Horner method
//!
//! \param   coefs  Array of polynomial coefficients
//! \param   x      The point at which to calculate the value of the polynomial
//!
//! \return  value of the polynomial at 'x'
//!
//!			 T(N) = Θ(N)
//!          M(N) = Θ(1)
//!
//====================================================================================================================================

template<typename Coef_t = vCoef_t::value_type, typename Res_t = base_t>
Res_t Horner(const std::vector<Coef_t> &coefs, Res_t x)
{
	if (coefs.size() == 1)
		return (coefs[0]);

	Res_t res = coefs.back();
	const auto size{ coefs.size() };
	for (auto i{ 1ull }; i <= size - 1; ++i)
	{
		res = res * x;
		res += coefs[size - 1 - i];
	}

	return (res);
}
