// ----------------------------------
// JSONの読み書き
//
//
// -----------------------------------

#include "PicoJsonReader.h"
#include "RapidJsonReader.h"

using namespace PicoJsonWrapper;
using namespace RapidJsonWrapper;

int main() 
{
	// PicoJsonWrapper　
	// 整数のInt型は使用できない
	// すべてdouble型で変換しないといけない！
	// そのため、整数を使用する際は、JsonReadType::Numeralを使用してください！
	// 外部ファイルのJsonファイル名前のみをコンストラクタで設定してください

	PicoJsonWrapper::JsonReader json("PicoJson");
	auto jsonParent = json.GetParentData("Test");
	
	std::cout << "Int: " << json.GetChildrenValue<JsonReadType::Numeral>(jsonParent, "Int") << std::endl;
	std::cout << "Double: " << json.GetChildrenValue<JsonReadType::Numeral>(jsonParent, "Double") << std::endl;
	std::cout << "String: " << json.GetChildrenValue<JsonReadType::String>(jsonParent, "String") << std::endl;
	std::cout << "Bool: " << json.GetChildrenValue<JsonReadType::Bool>(jsonParent, "Bool") << std::endl;
	
	auto arrayData = json.GetChildrenArrayValue(jsonParent,"Array");
	std::cout << "Array:" << std::endl;
	for (auto& data : arrayData)
	{
		std::cout << "\t" << data.get<std::string>() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "------------- NextJson ------------------" << std::endl;
	std::cout  << std::endl;

	// RapidJson
	// 整数・浮動小数・文字列・Bool型　扱えます。
	// 以下のように扱います。
	// 外部ファイルのJsonファイル名前のみをコンストラクタで設定してください

	RapidJsonWrapper::RapidJsonReader json2("RapidJson");

	std::cout << "Int : " << json2.GetInt("Int") << std::endl;
	std::cout << "Float : " << json2.GetFloat("Float") << std::endl;
	std::cout << "Double : " << json2.GetDouble("Double") << std::endl;
	std::cout << "String : " << json2.GetString("String") << std::endl;
	std::cout << "Bool : " << json2.GetBool("Bool") << std::endl;

	JsonValue parentValue = json2.GetParentValue("Type");

	std::cout << "Type Int : " << json2.GetInt(parentValue, "Int") << std::endl;
	std::cout << "Type Float : " << json2.GetFloat(parentValue, "Float") << std::endl;
	std::cout << "Type String : " << json2.GetString(parentValue, "String") << std::endl;

}
