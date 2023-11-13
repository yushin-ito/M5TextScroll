#include <M5Unified.h>

class M5TextScroll {
private:
  const uint8_t MAX_FONT_HEIGHT = 40;

  M5Canvas* canvas;
  bool _drawing;
  bool _changed;
  int32_t _x;
  int32_t _y;
  uint8_t _speed;
  uint32_t _bg_color;
  uint32_t _text_color;
  const lgfx::IFont* _font;
  int32_t cursor_x;
  char _text[256];
  size_t _text_len;
  size_t _text_pos;
  uint8_t scroll_count;

public:
  M5TextScroll();
  void setPosition(int32_t x, int32_t y);
  void setSpeed(uint8_t speed);
  void setBgColor(uint32_t color);
  void setTextColor(uint32_t color);
  void setFont(const lgfx::IFont* font);
  void setText(const char* text);
  void init(int32_t x, int32_t y);
  void start();
  void stop();
  bool isDrawing();
  bool isChanged();
  void setChanged(bool changed);
  void drawTextScroll();
  uint8_t getScrollCount();
};

class Context {
private:
  M5TextScroll* _ts;

public:
  Context(M5TextScroll* ts);
  M5TextScroll* getTextScroll();
};