#include "pch.h"
#include "Room.hpp"


Room::Room(std::string mName) : mName(mName)
{}

std::string Room::getName() {
	return mName;
}

void Room::setName(std::string roomName) {
	mName = roomName;
}

std::ostream& operator << (std::ostream& out, Room rArg) {
	out << rArg.mName << " ";
	return out;
}

std::istream & operator >> (std::istream & in, Room rArg) {
	in >> rArg.mName;
	return in;
}