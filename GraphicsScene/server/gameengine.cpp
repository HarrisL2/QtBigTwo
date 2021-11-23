#include "gameengine.h"

GameEngine::GameEngine(Server* ser) :
    server(ser)
{

}

void GameEngine::recieveData(Worker* sender, const QJsonObject& data) {

}
