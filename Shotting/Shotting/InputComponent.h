#pragma once
#include "PlayerMove.h"
#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public PlayerMove
{
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const uint8_t* keyState) override;

	//Ship.cpp�ňړ��ʂ̐��l�ݒ肷�邽�߂Ɏg�p����
	//���ɐi�ޗʂ̐ݒ�
	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	//��]����ʂ̐ݒ�
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	//�W�����v����ʂ̐ݒ�
	void SetMaxJumpSpeed(float speed) { mMaxJumpSpeed = speed; }


	//Ship.cpp�ŃL�[��ݒ肷�邽�߂Ɏg�p����
	//�E�ړ��̃L�[�̐ݒ�
	void SetRightKey(int key) { mRightKey = key; }
	//���ړ��̃L�[�̐ݒ�
	void SetLeftKey(int key) { mLeftKey = key; }
	//�W�����v�L�[�̐ݒ�
	void SetJumpKey(int key) { mJumpKey = key; }
	//�E��]�̃L�[�ݒ�
	void SetClockwiseKey(int key) { mClockwiseKey = key; }
	//����]�̃L�[�ݒ�
	void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }

private:
	//���ړ���
	float mMaxForwardSpeed;
	//��]��
	float mMaxAngularSpeed;
	//�W�����v��
	float mMaxJumpSpeed;
	//�E�ړ��L�[
	int mRightKey;
	//���ړ��L�[
	int mLeftKey;
	//�E��]�L�[
	int mRightRotateKey;
	//����]�L�[
	int mLeftRotateKey;
	//�W�����v�L�[
	int mJumpKey;
	//�E��]�L�[
	int mClockwiseKey;
	//����]�L�[
	int mCounterClockwiseKey;
};
