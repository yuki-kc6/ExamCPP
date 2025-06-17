#pragma once
#include "GameObject.h"
#include "global.h"

class EnemyBeam :
    public GameObject
{
public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetTarget(const Point& pos);
    void SetPos(float x, float y) { pos_.x = x; pos_.y = y; }
    void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; }//���ˏ�Ԃ�ݒ�
    bool IsFired() const { return isFired_; }//���ˏ�Ԃ��擾
    Rect GetRect()const { return {pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }//�v���C���[�̋�`���擾
protected:
private:
    int hImage_;//���̉摜�n���h��
    Point pos_;//�e�̍��W
    Point tpos_;//�^�[�Q�b�g�̍��W
    float speed_;//�ړ����x
    Point imageSize_;
    //int isize_x, isize_y;//�e�̕\���T�C�Y
    bool isFired_;//���˂���Ă��邩�ǂ��� true:���˂��ꂽ false ���˂���Ă��Ȃ�

};

