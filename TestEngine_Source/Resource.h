#pragma once
#include "CommonInclude.h"
namespace yw
{
	class Resource
	{
	public:
		Resource(ResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const wstring& path) = 0;

		const wstring& GetPath() { return m_path; }
		void SetPath(const wstring& path) { m_path = path; }

		void SetName(const std::wstring& name) { m_Name = name; }
		std::wstring& GetName() { return m_Name; }

	private:
		ResourceType m_Type;
		wstring m_path;	
		wstring m_Name;
		
	};
}


