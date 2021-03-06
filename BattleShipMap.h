
#include "Pane.h"
#include <string>
using namespace std;

#define MAP_SIZE 8
#ifndef CBattleShipMap_h
#define CBattleShipMap_h

class CBattleShipMap : public Pane {
public:
    CBattleShipMap(const char* name, int x = 4, int y = 4); // m_mapData 를 모두 0으로 초기화

    void Draw();
    void randomDeploy(); //m_mapData 를 randomize
    char data1 = '!';
    inline char& getFromCode(char const cmd[2]){
	    
	if (cmd[0]<=72 && cmd[0]>=65 && cmd[1]<'9' && cmd[1]>'0' ){
		return m_mapData[cmd[0] - 65][cmd[1] - 48 - 1];
	}

	else if (cmd[0]<=104 && cmd[0]>=97 && cmd[1]<'9'&& cmd[1]>'0' ){
		return m_mapData[cmd[0] - 97][cmd[1] - 48 - 1];
	}

	else {
		return data1;
	}	    
    }

protected:
    friend class CBattleShipApp;
    char m_mapData[MAP_SIZE][MAP_SIZE];

};

#endif
