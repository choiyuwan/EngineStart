#pragma once
#include "Resource.h"
namespace yw
{
	class ResourceManager
	{
	public:
		template <typename T>
		static T* Find(const wstring& key)
		{
			auto iter = m_Resources.find(key);

			if (iter == m_Resources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);			
		}

		template <typename T>
		static T* Load(const wstring& key, const wstring& path)
		{
			T* resource = ResourceManager::Find<T>(key);

			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(path))) 
			{
				assert(false);
			}

			resource->SetName(key);
			resource->SetPath(path);
			m_Resources.insert(make_pair(key, resource));

			return resource;
		}

	private:
		static map<wstring, Resource*> m_Resources;

	};
}


