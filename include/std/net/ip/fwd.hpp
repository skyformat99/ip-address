//
// ip/fwd.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef STDNET_IP_FWD_HPP
#define STDNET_IP_FWD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "std/net/detail/config.hpp"
#include <array>
#include <string>
#include <system_error>
#include <type_traits>

#if !defined(STDNET_NO_IOSTREAM)
# include <iosfwd>
#endif // !defined(STDNET_NO_IOSTREAM)

#include "std/net/detail/push_options.hpp"

namespace std {
namespace net {
namespace ip {

class address;

// address comparisons:
bool operator==(const address&, const address&) STDNET_NOEXCEPT;
bool operator!=(const address&, const address&) STDNET_NOEXCEPT;
bool operator< (const address&, const address&) STDNET_NOEXCEPT;
bool operator> (const address&, const address&) STDNET_NOEXCEPT;
bool operator<=(const address&, const address&) STDNET_NOEXCEPT;
bool operator>=(const address&, const address&) STDNET_NOEXCEPT;

// address creation:
address make_address(const char*);
address make_address(const char*, std::error_code&) STDNET_NOEXCEPT;
address make_address(const std::string&);
address make_address(const std::string&, std::error_code&) STDNET_NOEXCEPT;

#if !defined(STDNET_NO_IOSTREAM)

// address I/O:
template<class CharT, class Traits>
  basic_ostream<CharT, Traits>& operator<<(
    basic_ostream<CharT, Traits>&, const address&);

#endif // !defined(STDNET_NO_IOSTREAM)

class address_v4;

// address_v4 comparisons:
bool operator==(const address_v4&, const address_v4&) STDNET_NOEXCEPT;
bool operator!=(const address_v4&, const address_v4&) STDNET_NOEXCEPT;
bool operator< (const address_v4&, const address_v4&) STDNET_NOEXCEPT;
bool operator> (const address_v4&, const address_v4&) STDNET_NOEXCEPT;
bool operator<=(const address_v4&, const address_v4&) STDNET_NOEXCEPT;
bool operator>=(const address_v4&, const address_v4&) STDNET_NOEXCEPT;

// address_v4 creation:
address_v4 make_address_v4(unsigned long);
address_v4 make_address_v4(const std::array<unsigned char, 4>&);
address_v4 make_address_v4(const char*);
address_v4 make_address_v4(const char*, error_code&) STDNET_NOEXCEPT;
address_v4 make_address_v4(const std::string&);
address_v4 make_address_v4(const std::string&, std::error_code&) STDNET_NOEXCEPT;

#if !defined(STDNET_NO_IOSTREAM)

// address_v4 I/O:
template<class CharT, class Traits>
  basic_ostream<CharT, Traits>& operator<<(
    basic_ostream<CharT, Traits>&, const address_v4&);

#endif // !defined(STDNET_NO_IOSTREAM)

class address_v6;

// address_v6 comparisons:
bool operator==(const address_v6&, const address_v6&) STDNET_NOEXCEPT;
bool operator!=(const address_v6&, const address_v6&) STDNET_NOEXCEPT;
bool operator< (const address_v6&, const address_v6&) STDNET_NOEXCEPT;
bool operator> (const address_v6&, const address_v6&) STDNET_NOEXCEPT;
bool operator<=(const address_v6&, const address_v6&) STDNET_NOEXCEPT;
bool operator>=(const address_v6&, const address_v6&) STDNET_NOEXCEPT;

// address_v6 creation:
address_v6 make_address_v6(const std::array<unsigned char, 16>&, unsigned long = 0);
address_v6 make_address_v6(const char*);
address_v6 make_address_v6(const char*, error_code&) STDNET_NOEXCEPT;
address_v6 make_address_v6(const std::string&);
address_v6 make_address_v6(const std::string&, error_code&) STDNET_NOEXCEPT;

#if !defined(STDNET_NO_IOSTREAM)

// address_v6 I/O:
template<class CharT, class Traits>
  basic_ostream<CharT, Traits>& operator<<(
    basic_ostream<CharT, Traits>&, const address_v6&);

#endif // !defined(STDNET_NO_IOSTREAM)

class bad_address_cast;

// address conversion:
template <class T> T address_cast(const address&,
  typename enable_if<is_same<T, address>::value>::type* = 0) STDNET_NOEXCEPT;
template <class T> T address_cast(const address&,
  typename enable_if<is_same<T, address_v4>::value>::type* = 0);
template <class T> T address_cast(const address&,
  typename enable_if<is_same<T, address_v6>::value>::type* = 0);
template <class T> T address_cast(const address_v4&,
  typename enable_if<is_same<T, address>::value>::type* = 0) STDNET_NOEXCEPT;
template <class T> T address_cast(const address_v4&,
  typename enable_if<is_same<T, address_v4>::value>::type* = 0) STDNET_NOEXCEPT;
template <class T> T address_cast(const address_v4&,
  typename enable_if<is_same<T, address_v6>::value>::type* = 0) STDNET_NOEXCEPT;
template <class T> T address_cast(const address_v6&,
  typename enable_if<is_same<T, address>::value>::type* = 0) STDNET_NOEXCEPT;
template <class T> T address_cast(const address_v6&,
  typename enable_if<is_same<T, address_v4>::value>::type* = 0);
template <class T> T address_cast(const address_v6&,
  typename enable_if<is_same<T, address_v6>::value>::type* = 0) STDNET_NOEXCEPT;

} // namespace ip
} // namespace net
} // namespace std

#include "std/net/detail/pop_options.hpp"

#endif // STDNET_IP_FWD_HPP