#pragma once
#include "SDL/SDL.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "Actor.h"
#include <cstdint>

class Game 
{
public:
	Game();
	//ゲームのメイン画面の生成
	void Initialize();
	//スタート画面やゲームオーバー画面の生成
	bool Initialize2();
	//ゲームループ処理
	void RunLoop();
	//ゲーム終了時のメモリ解放や削除
	void Shutdown();

	//生成物の生成と削除
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	SDL_Texture* GetTexture(const std::string& fileName);
	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	///ゲームメインの生成
	void LoadData();
	//ゲーム終了時の削除
	void UnloadData();
	// ゲームスタート時の生成
	void StartData();
	
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;

	//プレイヤーの宣言
	class Ship* mShip;
	//隕石の宣言
	std::vector<class Asteroid*> mAsteroids;
	//スタート画面の宣言
	class Start* mStart;
};