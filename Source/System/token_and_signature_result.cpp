﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#include "pch.h"
#include "utils.h"
#include "shared_macros.h"
#include "xsapi/system.h"

NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_CPP_BEGIN

token_and_signature_result::token_and_signature_result(
    _In_ string_t token,
    _In_ string_t signature,
    _In_ string_t xuid,
    _In_ string_t gamertag,
    _In_ string_t userHash,
    _In_ string_t ageGroup,
    _In_ string_t privileges,
    _In_ string_t webAccountId,
    _In_ string_t reserved
    ) :
    m_token(std::move(token)), 
    m_signature(std::move(signature)), 
    m_xboxUserId(std::move(xuid)), 
    m_xboxUserHash(std::move(userHash)), 
    m_gamerTag(std::move(gamertag)),
    m_ageGroup(std::move(ageGroup)),
    m_privileges(std::move(privileges)),
    m_webAccountId(std::move(webAccountId)),
    m_reserved(std::move(reserved))
{
}

token_and_signature_result::token_and_signature_result()
{
}

#ifndef DEFAULT_MOVE_ENABLED
token_and_signature_result::token_and_signature_result(token_and_signature_result&& other)
{
    *this = std::move(other);
}

token_and_signature_result& token_and_signature_result::operator = (token_and_signature_result&& other)
{
    if (this != &other)
    {
        m_token = std::move(other.m_token);
        m_signature = std::move(other.m_signature);
        m_xboxUserId = std::move(other.m_xboxUserId);
        m_xboxUserHash = std::move(other.m_xboxUserHash);
        m_gamerTag = std::move(other.m_gamerTag);
        m_ageGroup = std::move(other.m_ageGroup);
        m_privileges = std::move(other.m_privileges);
        m_webAccountId = std::move(other.m_webAccountId);
        m_reserved = std::move(other.m_reserved);
    }

    return *this;
}
#endif

const string_t& token_and_signature_result::xbox_user_id() const
{
    return m_xboxUserId;
}

const string_t& token_and_signature_result::token() const
{
    return m_token;
}

const string_t& token_and_signature_result::signature() const
{
    return m_signature;
}

const string_t& token_and_signature_result::gamertag() const
{
    return m_gamerTag;
}

const string_t& token_and_signature_result::xbox_user_hash() const
{
    return m_xboxUserHash;
}

const string_t& token_and_signature_result::age_group() const
{
    return m_ageGroup;
}

const string_t& token_and_signature_result::privileges() const
{
    return m_privileges;
}

const string_t& token_and_signature_result::reserved() const
{
    return m_reserved;
}

const string_t& token_and_signature_result::web_account_id() const
{
    return m_webAccountId;
}

#if UWP_API
token_and_signature_result::token_and_signature_result(
    Windows::Security::Authentication::Web::Core::WebTokenRequestResult^ tokenResult
    ):
    m_tokenResult(tokenResult)
{
}

Windows::Security::Authentication::Web::Core::WebTokenRequestResult^ 
token_and_signature_result::token_request_result() const
{
    return m_tokenResult;
}
#endif


NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_CPP_END
