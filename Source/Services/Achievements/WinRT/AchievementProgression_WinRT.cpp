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
#include "AchievementProgression_winrt.h"
#include "Utils_WinRT.h"

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation::Collections;
using namespace Windows::Foundation;
using namespace Microsoft::Xbox::Services::System;
using namespace xbox::services::achievements;

NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_BEGIN

AchievementProgression::AchievementProgression(
    _In_ xbox::services::achievements::achievement_progression cppObj
    ) :
    m_cppObj(std::move(cppObj))
{
    m_requirements = ref new Vector<AchievementRequirement^>();
    auto& cppRequirements = m_cppObj.requirements();
    for (const auto& requirement : cppRequirements)
    {
        m_requirements->Append(ref new AchievementRequirement(requirement));
    }

}

IVectorView<AchievementRequirement^>^
AchievementProgression::Requirements::get()
{
    return m_requirements->GetView();
}

NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_END