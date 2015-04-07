#pragma once

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <iostream>
#include <vector>

namespace RapidJsonWrapper
{
	using JsonValue = rapidjson::Value&;

	class RapidJsonReader
	{
	public:
		RapidJsonReader(const std::string& fileName);

		rapidjson::Value& GetParentValue(const std::string &keyName);

		bool GetBool(const std::string &keyName)const;
		int GetInt(const std::string &keyName)const;
		float GetFloat(const std::string &keyName)const;
		double GetDouble(const std::string &keyName)const;
		std::string GetString(const std::string &keyName)const;

		int GetInt(const rapidjson::Value& parentValue, const std::string &valueName);
		bool GetBool(const rapidjson::Value& parentValue, const std::string &valueName);
		float GetFloat(const rapidjson::Value& parentValue, const std::string &valueName);
		double GetDouble(const rapidjson::Value& parentValue, const std::string &valueName);
		std::string GetString(const rapidjson::Value& parentValue, const std::string &valueName);

		std::vector<int> GetIntArray(const std::string &keyName)const;
		std::vector<float> GetFloatArray(const std::string &keyName)const;
		std::vector<double> GetDoubleArray(const std::string &keyName)const;
		std::vector<std::string> GetStringArray(const std::string &keyName)const;


	private:
		bool Read(const std::string& filePath);
		FILE* fp;
		char buf[1024];
		rapidjson::Document doc;

	};
}
