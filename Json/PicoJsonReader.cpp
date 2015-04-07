#include "PicoJsonReader.h"

using namespace picojson;
using namespace PicoJsonWrapper;

JsonReader::JsonReader(const std::string& fileName)
{
	Read(fileName + ".json");
}


bool JsonReader::Read(const std::string& filePath)
{
	fileStream.open(filePath, std::ios::binary);
	if (!fileStream.is_open()) return false;

	stringData << fileStream.rdbuf();
	fileStream.close();

	stringData >> valueData;
	auto err = get_last_error();

	if (!err.empty()) {
		std::cout << err << std::endl;
		return false;
	}

	return true;
}

object& JsonReader::GetParentData(const std::string& name)
{
	return valueData.get<object>()[name].get<object>();
}

array& JsonReader::GetChildrenArrayValue(picojson::object& parentData, const std::string& name)
{
	return parentData[name].get<array>();
}