#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "picojson.h"

namespace PicoJsonWrapper
{
	struct JsonReadType
	{
		using String = std::string;
		using Numeral = double;
		using Bool = bool;
	};

	class JsonReader
	{
	public:
		JsonReader(const std::string& fileName);

		picojson::object& GetParentData(const std::string& name);

		template<typename Type>
		Type& GetChildrenValue(picojson::object& parentData, const std::string& name)
		{
			return parentData[name].get<Type>();
		}

		picojson::array& GetChildrenArrayValue(picojson::object& parentData, const std::string& name);

	private:
		bool Read(const std::string& filePath);

		std::stringstream stringData;
		std::ifstream     fileStream;
		picojson::value valueData;

	};

}