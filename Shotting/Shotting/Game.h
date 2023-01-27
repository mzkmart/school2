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
	//�Q�[���̃��C����ʂ̐���
	void Initialize();
	//�X�^�[�g��ʂ�Q�[���I�[�o�[��ʂ̐���
	bool Initialize2();
	//�Q�[�����[�v����
	void RunLoop();
	//�Q�[���I�����̃����������폜
	void Shutdown();

	//�������̐����ƍ폜
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
	///�Q�[�����C���̐���
	void LoadData();
	//�Q�[���I�����̍폜
	void UnloadData();
	// �Q�[���X�^�[�g���̐���
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

	//�v���C���[�̐錾
	class Ship* mShip;
	//覐΂̐錾
	std::vector<class Asteroid*> mAsteroids;
	//�X�^�[�g��ʂ̐錾
	class Start* mStart;
};