/*
 * TRAKTOR
 * Copyright (c) 2024 Anders Pistol.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
#include "Core/Serialization/ISerializer.h"
#include "Core/Serialization/Member.h"
#include "Core/Serialization/MemberEnum.h"
#include "Render/Editor/Shader/UniformDeclaration.h"

namespace traktor::render
{

T_IMPLEMENT_RTTI_EDIT_CLASS(L"traktor.render.UniformDeclaration", 0, UniformDeclaration, ISerializable)

void UniformDeclaration::serialize(ISerializer& s)
{
	const MemberEnum< ParameterType >::Key c_ParameterType_Keys[] =
	{
		{ L"Scalar", ParameterType::Scalar },
		{ L"Vector", ParameterType::Vector },
		{ L"Matrix", ParameterType::Matrix },
		{ L"Texture2D", ParameterType::Texture2D },
		{ L"Texture3D", ParameterType::Texture3D },
		{ L"TextureCube", ParameterType::TextureCube },
		{ L"StructBuffer", ParameterType::StructBuffer },
		{ L"Image2D", ParameterType::Image2D },
		{ L"Image3D", ParameterType::Image3D },
		{ L"ImageCube", ParameterType::ImageCube },
		{ L"AccelerationStructure""", ParameterType::AccelerationStructure },
		{ 0 }
	};

	const MemberEnum< UpdateFrequency >::Key c_UpdateFrequency_Keys[] =
	{
		{ L"Once", UpdateFrequency::Once },
		{ L"Frame", UpdateFrequency::Frame },
		{ L"Draw", UpdateFrequency::Draw },
		{ 0 }
	};

	s >> MemberEnum< ParameterType >(L"type", m_type, c_ParameterType_Keys);
	s >> Member< int32_t >(L"length", m_length);
	s >> MemberEnum< UpdateFrequency >(L"frequency", m_frequency, c_UpdateFrequency_Keys);
}

}
