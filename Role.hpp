#pragma once

class Role {
public:
	enum RoleType
	{
		STUDENT_ROLE,
		TEACHER_ROLE,
		GUEST_ROLE,
		ADMINISTRATOR_ROLE
	};

	Role(RoleType type);

	RoleType getType();

protected:
	RoleType mType;

};
