#pragma once
#include "Repository.hpp"
#include "Room.hpp"

class RoomRepository : public Repository<Room>{
public:


	Room* findByName(std::string roomName) {
		for (int i = 0; i < mEntities.size(); i++) {
			if (mEntities[i]->getName() == roomName)
				return mEntities[i];
		}

		return 0;
	};


};
