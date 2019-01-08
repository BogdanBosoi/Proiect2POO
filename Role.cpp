#include "pch.h"
#include "Role.hpp"



Role::Role(RoleType type):mType(type){

}

Role::RoleType Role::getType()
{
	return mType;
}



