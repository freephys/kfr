/**
 * Copyright (C) 2016 D Levin (http://www.kfrlib.com)
 * This file is part of KFR
 *
 * KFR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * KFR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with KFR.
 *
 * If GPL is not suitable for your project, you must purchase a commercial license to use KFR.
 * Buying a commercial license is mandatory as soon as you develop commercial activities without
 * disclosing the source code of your own applications.
 * See http://www.kfrlib.com for details.
 */
#pragma once

#include "../base/sin_cos.hpp"
#include "../expressions/basic.hpp"

namespace kfr
{

template <typename T>
auto jaehne(T magn, size_t size)
{
    return typed<T>(magn * sin(c_pi<T, 1, 2> * sqr(linspace(T(0), T(size), size, false)) / size), size);
}

template <typename T>
auto swept(T magn, size_t size)
{
    return typed<T>(
        magn * sin(c_pi<T, 1, 4> * sqr(sqr(linspace(T(0), T(size), size, false)) / sqr(T(size))) * T(size)),
        size);
}

namespace intrinsics
{
template <typename T>
KFR_SINTRIN T rawsine(T x)
{
    return fastsin(x * c_pi<T, 2>);
}
template <typename T>
KFR_SINTRIN T sinenorm(T x)
{
    return rawsine(fract(x));
}
template <typename T>
KFR_SINTRIN T sine(T x)
{
    return sinenorm(c_recip_pi<T, 1, 2> * x);
}

template <typename T>
KFR_SINTRIN T rawsquare(T x)
{
    return select(x < T(0.5), T(1), -T(1));
}
template <typename T>
KFR_SINTRIN T squarenorm(T x)
{
    return rawsquare(fract(x));
}
template <typename T>
KFR_SINTRIN T square(T x)
{
    return squarenorm(c_recip_pi<T, 1, 2> * x);
}

template <typename T>
KFR_SINTRIN T rawsawtooth(T x)
{
    return T(1) - 2 * x;
}
template <typename T>
KFR_SINTRIN T sawtoothnorm(T x)
{
    return rawsawtooth(fract(x));
}
template <typename T>
KFR_SINTRIN T sawtooth(T x)
{
    return sawtoothnorm(c_recip_pi<T, 1, 2> * x);
}

template <typename T>
KFR_SINTRIN T isawtoothnorm(T x)
{
    return T(-1) + 2 * fract(x + 0.5);
}
template <typename T>
KFR_SINTRIN T isawtooth(T x)
{
    return isawtoothnorm(c_recip_pi<T, 1, 2> * x);
}

template <typename T>
KFR_SINTRIN T rawtriangle(T x)
{
    return 1 - abs(4 * x - 2);
}
template <typename T>
KFR_SINTRIN T trianglenorm(T x)
{
    return rawtriangle(fract(x + 0.25));
}
template <typename T>
KFR_SINTRIN T triangle(T x)
{
    return trianglenorm(c_recip_pi<T, 1, 2> * x);
}

}
KFR_I_FN(rawsine)
KFR_I_FN(sine)
KFR_I_FN(sinenorm)
KFR_I_FN(rawsquare)
KFR_I_FN(square)
KFR_I_FN(squarenorm)
KFR_I_FN(rawtriangle)
KFR_I_FN(triangle)
KFR_I_FN(trianglenorm)
KFR_I_FN(rawsawtooth)
KFR_I_FN(sawtooth)
KFR_I_FN(sawtoothnorm)
KFR_I_FN(isawtooth)
KFR_I_FN(isawtoothnorm)

template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 rawsine(const T1& x)
{
    return intrinsics::rawsine(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::rawsine, E1> rawsine(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 sine(const T1& x)
{
    return intrinsics::sine(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::sine, E1> sine(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 sinenorm(const T1& x)
{
    return intrinsics::sinenorm(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::sinenorm, E1> sinenorm(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 rawsquare(const T1& x)
{
    return intrinsics::rawsquare(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::rawsquare, E1> rawsquare(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 square(const T1& x)
{
    return intrinsics::square(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::square, E1> square(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 squarenorm(const T1& x)
{
    return intrinsics::squarenorm(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::squarenorm, E1> squarenorm(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 rawtriangle(const T1& x)
{
    return intrinsics::rawtriangle(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::rawtriangle, E1> rawtriangle(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 triangle(const T1& x)
{
    return intrinsics::triangle(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::triangle, E1> triangle(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 trianglenorm(const T1& x)
{
    return intrinsics::trianglenorm(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::trianglenorm, E1> trianglenorm(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 rawsawtooth(const T1& x)
{
    return intrinsics::rawsawtooth(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::rawsawtooth, E1> rawsawtooth(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 sawtooth(const T1& x)
{
    return intrinsics::sawtooth(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::sawtooth, E1> sawtooth(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 sawtoothnorm(const T1& x)
{
    return intrinsics::sawtoothnorm(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::sawtoothnorm, E1> sawtoothnorm(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 isawtooth(const T1& x)
{
    return intrinsics::isawtooth(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::isawtooth, E1> isawtooth(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
template <typename T1, KFR_ENABLE_IF(is_numeric<T1>::value)>
KFR_INTRIN T1 isawtoothnorm(const T1& x)
{
    return intrinsics::isawtoothnorm(x);
}
template <typename E1, KFR_ENABLE_IF(is_input_expression<E1>::value)>
KFR_INTRIN expr_func<fn::isawtoothnorm, E1> isawtoothnorm(E1&& x)
{
    return { {}, std::forward<E1>(x) };
}
}
