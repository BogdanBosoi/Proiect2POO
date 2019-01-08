#pragma once
#include <vector>

template<class Entity>
class Repository {
public: 
	void add(Entity* ob) {mEntities.push_back(ob);}
	
	void remove(Entity* ob) {

		for (int i = 0; i < mEntities.size(); i++) {
			if (mEntities[i] == ob) {
				mEntities[i] = mEntities[mEntities.size() - 1];
				delete mEntities[mEntities.size() - 1];
				break;
			}
		}
	}

	void print() {
		for (int i = 0; i < mEntities.size(); i++)
			std::cout << mEntities[i] << " ";
	}

	int getSize() { return mEntities.size(); }
protected:
	std::vector<Entity*> mEntities;
};