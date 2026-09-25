

#pragma once

#include <limits>
#include <cmath>
#include <cstdint>
#include <bit>


template <
    typename scalar
>
class Math {

public: // constexpr fields and methods:

    static constexpr scalar Sqr(scalar x) {
        return x*x;
    }

    static constexpr scalar Cube(scalar x) {
        return Sqr(x)*x;
    }

    static constexpr scalar Raise4(scalar x) {
        return Sqr(x)*Sqr(x);
    }

    static constexpr scalar Raise5(scalar x) {
        return Sqr(x)*Cube(x);
    }

    // nanoscale, 10^-9 unitless
    static constexpr scalar nsmall = 1.0E-9;
    // picoscale, 10^-10 unitless
    static constexpr scalar psmall = 1.0E-12;
    // femtoscale, 10^-12 unitless
    static constexpr scalar fsmall = 1.0E-15;
    static constexpr scalar tiny = fsmall;

public: // constexpr fields:

    static constexpr scalar e = 2.71828182845904523536028747135; /* e */
    static constexpr scalar log2e = 1.44269504088896340735992468100;      /* log_2 (e) */
    static constexpr scalar log10e = 0.43429448190325182765112891892;      /* log_10 (e) */
    static constexpr scalar sqrt2 = 1.41421356237309504880168872421;      /* sqrt(2) */
    static constexpr scalar sqrt1o2 = 0.70710678118654752440084436210;      /* sqrt(1/2) */
    static constexpr scalar sqrt3 =   1.73205080756887729352744634151;      /* sqrt(3) */
    static constexpr scalar pi =      3.14159265358979323846264338328;      /* pi */
    static constexpr scalar pio2 =    1.57079632679489661923132169164;      /* pi/2 */
    static constexpr scalar pio4 =     0.78539816339744830961566084582;     /* pi/4 */
    static constexpr scalar sqrtpi =  1.77245385090551602729816748334;      /* sqrt(pi) */
    static constexpr scalar twoosqrtpi = 1.12837916709551257389615890312;      /* 2/sqrt(pi) */
    static constexpr scalar oneopi =    0.31830988618379067153776752675;      /* 1/pi */
    static constexpr scalar twoopi =    0.63661977236758134307553505349;      /* 2/pi */
    static constexpr scalar ln10 =    2.30258509299404568401799145468;      /* ln(10) */
    static constexpr scalar ln2 =     0.69314718055994530941723212146;      /* ln(2) */
    static constexpr scalar lnpi =    1.14472988584940017414342735135;      /* ln(pi) */
    static constexpr scalar euler =   0.57721566490153286060651209008;      /* Euler constant */

    static constexpr scalar fourpi = Raise4(pi);
    static constexpr scalar oneo8pi = Raise4(Raise4(oneopi));
    static constexpr scalar oneo4pi = Raise4(oneopi);


public: // API:

    /*!
    \brief Computes the fabs function
    \author Lucius Schoenbaum
    \date 11/07/2025
    \param[in] x The argument
    \return \f$\abs(x)\f$
    */
    static constexpr scalar cfabs(scalar x) noexcept {
        return x < 0 ? -x : x;
    }


    /*!
    \brief Computes the square root as constexpr,
    while allowing constexpr-valid functions to be defined
    that have the performance degradation of constexpr evaluation
    when forced to execute at runtime.
    \author Vladimir Florinski
    \author Lucius Schoenbaum
    \date 11/07/2025
    \param[in] x The argument
    \return \f$\sqrt{x}\f$
    */
    static constexpr scalar csqrt(scalar x) {
        if (std::is_constant_evaluated()) {
            if (x < 0) return std::numeric_limits<double>::quiet_NaN();
            if (x == 0) return 0;
            const int maxiter = 10;
            int niter = 0;
            double y = x;

            // Initial reduction based on a bitwise representation of a "double"
            uint64_t y_bit = std::bit_cast<uint64_t>(y);
            uint64_t processed = (((((y_bit & 0x7FF0000000000000ULL) - 0x3FF0000000000000ULL) >> 1) + 0x3FF0000000000000ULL) & 0x7FF0000000000000ULL) | (y_bit & 0x000FFFFFFFFFFFFFULL);
            y = std::bit_cast<double>(processed);

            // Henon's method (Newton iterations)
            while ((cfabs((y * y - x) / x) > tiny) && (niter < maxiter)) {
                y = 0.5 * (y + x / y);
                niter++;
            }
            return y;
        } else {
            return std::sqrt(x);
        }
    }



};


