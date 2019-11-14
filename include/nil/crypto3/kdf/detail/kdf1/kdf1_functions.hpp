//---------------------------------------------------------------------------//
// Copyright (c) 2019 Nil Foundation AG
// Copyright (c) 2019 Mikhail Komarov <nemo@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_KDF_KDF1_FUNCTIONS_HPP
#define CRYPTO3_KDF_KDF1_FUNCTIONS_HPP

#include <nil/crypto3/kdf/detail/kdf1/kdf1_policy.hpp>

namespace nil {
    namespace crypto3 {
        namespace kdf {
            namespace detail {
                template<typename Hash>
                struct kdf1_functions : public kdf1_policy<Hash> {
                    typedef kdf1_policy<Hash> policy_type;

                    typedef typename policy_type::hash_type hash_type;

                    constexpr static const std::size_t digest_bits = policy_type::digest_bits;
                    typedef typename policy_type::digest_type digest_type;
                };
            }
        }
    }
}

#endif    // CRYPTO3_HKDF_FUNCTIONS_HPP