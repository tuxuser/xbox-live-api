//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#pragma once 
#include "xsapi/social.h"
#include "RealTimeActivitySubscriptionState_WinRT.h"

NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_BEGIN

public ref class SocialRelationshipChangeSubscription sealed
{
public:
    /// <summary>
    /// The current state of the subscription.
    /// </summary>
    property Microsoft::Xbox::Services::RealTimeActivity::RealTimeActivitySubscriptionState State{ Microsoft::Xbox::Services::RealTimeActivity::RealTimeActivitySubscriptionState get(); }

    /// <summary>
    /// The resource uri for the request.
    /// </summary>
    DEFINE_PTR_PROP_GET_STR_OBJ(ResourceUri, resource_uri);

    /// <summary>
    /// The unique subscription id for the request.
    /// </summary>
    DEFINE_PTR_PROP_GET_OBJ(SubscriptionId, subscription_id, uint32_t);

    /// <summary>
    /// The Xbox user ID for the user who's social graph changes are being listed for.
    /// </summary>
    DEFINE_PTR_PROP_GET_STR_OBJ(XboxUserId, xbox_user_id);

internal:
    SocialRelationshipChangeSubscription(_In_ std::shared_ptr<xbox::services::social::social_relationship_change_subscription> cppObj);
    std::shared_ptr<xbox::services::social::social_relationship_change_subscription> GetCppObj() const;

private:
    std::shared_ptr<xbox::services::social::social_relationship_change_subscription> m_cppObj;
};

NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_END