#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "common.h"

CLASS_PTR(Image)
class Image
{
public:
    static ImageUPtr Load(const std::string& filepath); //이미지 로드
    static ImageUPtr Create(int width, int height, int channelCount = 4); //이미지 할당
    ~Image();

    const uint8_t* GetData() const {return m_data;}
    int GetWidth() const {return m_width;}
    int GetHeight() const {return m_height;}
    int GetChannelCount() const {return m_channelCount;}

    void SetCheckImage(int gridX, int gridY); //체크보드 이미지 만들기
private:
    Image() {}
    bool LoadWithStb(const std::string& filepath);
    bool Allocate(int width, int height, int channelCount);
    int m_width{0};
    int m_height{0};
    int m_channelCount{0};
    uint8_t* m_data{nullptr};
};

#endif //__IMAGE_H__

//cpu에 이미지 올리기
/*glGenTextures(1, &m_texture); //1장 만들겠다.
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //텍스트 좌표계 S, T -> X, Y
    //0 ,1 사이가 아니면 엣지에 있는 색을 가져다 쓰겠다.

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, //0 -> 기본 이미지 사이즈 커질수록 이미지가 줄어듦
                 image->GetWidth(), image->GetHeight(), 0, //앞 쪽은 GPU
                 GL_RGB, GL_UNSIGNED_BYTE, image->GetData());
                //이미지에서의 RPG값
                //이미지를 cpu에서 복사해서 gpu로 가져옴*/
//gpu에 이미지 올리기