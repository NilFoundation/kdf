//---------------------------------------------------------------------------//
// Copyright (c) 2019 Nil Foundation AG
// Copyright (c) 2019 Mikhail Komarov <nemo@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_HKDF_POLICY_HPP
#define CRYPTO3_HKDF_POLICY_HPP

#include <nil/crypto3/detail/type_traits.hpp>

namespace nil {
    namespace crypto3 {
        namespace kdf {
            using namespace nil::crypto3::detail;

            namespace detail {
                template<typename Construction, typename = void>
                struct sp800_56a_policy {};

                template<typename Hash>
                struct sp800_56a_policy<Hash, typename std::enable_if<is_hash<Hash>::value>::type> {
                    typedef Hash hash_type;
                };

                template<typename MessageAuthenticationCode>
                struct sp800_56a_policy<MessageAuthenticationCode,
                                        typename std::enable_if<is_mac<MessageAuthenticationCode>::value>::type> {
                    typedef MessageAuthenticationCode mac_type;
                };

                template<typename Hash>
                struct sp800_56a_policy<mac::hmac<Hash>,
                                        typename std::enable_if<is_mac<mac::hmac<Hash>>::value>::type> {
                    typedef Hash hash_type;
                    typedef mac::hmac<Hash> mac_type;

                    constexpr static const std::size_t min_key_bits = mac_type::min_key_bits;
                    constexpr static const std::size_t max_key_bits = mac_type::max_key_bits;
                    typedef typename mac_type::key_type key_type;
                };
            }    // namespace detail
        }        // namespace kdf
    }            // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_HKDF_POLICY_HPP