#pragma once

struct lua_State;
void configuregerefiLuaHooks(lua_State*);
void luaDeInitPins();

struct AirmassModelBase;
AirmassModelBase& getLuaAirmassModel();
