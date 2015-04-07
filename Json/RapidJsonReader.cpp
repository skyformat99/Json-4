#include "RapidJsonReader.h"

using namespace rapidjson;
using namespace RapidJsonWrapper;

RapidJsonReader::RapidJsonReader(const std::string& fileName)
{
	Read(fileName + ".json");
}



bool RapidJsonReader::Read(const std::string& filePath)
{
	fopen_s(&fp, filePath.c_str(), "rb");
	FileReadStream rs(fp, buf, sizeof(buf));

	doc.ParseStream(rs);

	bool error = doc.HasParseError();

	if (error){
		std::cout << "ƒp[ƒXŽ¸”s" << std::endl;
		return false;
	}

	fclose(fp);

	return true;
}

Value& RapidJsonReader::GetParentValue(const std::string &keyName)
{
	return doc[keyName.c_str()];
}

bool RapidJsonReader::GetBool(const std::string &keyName)const
{
	return doc[keyName.c_str()].GetBool();
}

int RapidJsonReader::GetInt(const std::string &keyName)const
{
	return doc[keyName.c_str()].GetInt();
}

float RapidJsonReader::GetFloat(const std::string &keyName)const
{
	return static_cast<float>(doc[keyName.c_str()].GetDouble());
}

double RapidJsonReader::GetDouble(const std::string &keyName)const
{
	return doc[keyName.c_str()].GetDouble();
}

std::string RapidJsonReader::GetString(const std::string &keyName)const
{
	return doc[keyName.c_str()].GetString();
}


std::vector<int> RapidJsonReader::GetIntArray(const std::string &keyName)const
{
	std::vector<int> v;
	const Value& a = doc[keyName.c_str()];
	SizeType num = a.Size();

	for (SizeType i = 0; i < num; i++){
		v.push_back(a[i].GetInt());
	}

	return v;
}

std::vector<float> RapidJsonReader::GetFloatArray(const std::string &keyName)const
{
	std::vector<float> v;
	const Value& a = doc[keyName.c_str()];
	SizeType num = a.Size();

	for (SizeType i = 0; i < num; i++){
		v.push_back(static_cast<float>(a[i].GetDouble()));
	}

	return v;
}


std::vector<double> RapidJsonReader::GetDoubleArray(const std::string &keyName)const
{
	std::vector<double> v;
	const Value& a = doc[keyName.c_str()];
	SizeType num = a.Size();

	for (SizeType i = 0; i < num; i++){
		v.push_back(a[i].GetDouble());
	}

	return v;
}

std::vector<std::string> RapidJsonReader::GetStringArray(const std::string &keyName)const
{
	std::vector<std::string> v;
	const Value& a = doc[keyName.c_str()];
	SizeType num = a.Size();

	for (SizeType i = 0; i < num; i++){
		v.push_back(a[i].GetString());
	}

	return v;
}



int RapidJsonReader::GetInt(const Value& parentValue, const std::string &valueName)
{
	return parentValue[valueName.c_str()].GetInt();
}

bool RapidJsonReader::GetBool(const Value& parentValue, const std::string &valueName)
{
	return parentValue[valueName.c_str()].GetBool();
}

float RapidJsonReader::GetFloat(const Value& parentValue, const std::string &valueName)
{
	return static_cast<float>(parentValue[valueName.c_str()].GetDouble());
}

double RapidJsonReader::GetDouble(const Value& parentValue, const std::string &valueName)
{
	return parentValue[valueName.c_str()].GetDouble();
}

std::string RapidJsonReader::GetString(const Value& parentValue, const std::string &valueName)
{
	return parentValue[valueName.c_str()].GetString();
}
