#include "TmxFunc\TmxFunc.h"


// functions depending on variable types
namespace TmxFinc {
	// int 

	int GetObjectInt(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup)
	{

		for (size_t i = 0; i < ObjectGroup->GetNumObjects(); i++)
		{

			if (ObjectName == ObjectGroup->GetObject(i)->GetName())
			{

				if (ObjectGroup->GetObject(i)->GetProperties().HasProperty(PropertyName))



					return ObjectGroup->GetObject(i)->GetProperties().GetIntProperty(PropertyName);
			}
		}
	}


	// string
	std::string GetObjectString(std::string ObjectName, std::string PropertyName, const Tmx::ObjectGroup *ObjectGroup)
	{

		for (size_t i = 0; i < ObjectGroup->GetNumObjects(); i++)
		{

			if (ObjectName == ObjectGroup->GetObject(i)->GetName())
			{


				if (ObjectGroup->GetObject(i)->GetProperties().HasProperty(PropertyName))

					return ObjectGroup->GetObject(i)->GetProperties().GetStringProperty(PropertyName);
			}
		}
	}

	// name  
}