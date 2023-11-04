#include <M5Unified.h>

class M5TextScroll {
private:
  M5Canvas* canvas;
  int32_t _x;
  int32_t _y;
  uint8_t _scroll_pixel;
  uint32_t _bg_color;
  uint32_t _text_color;
  const lgfx::IFont* _text_font;
  int32_t cursor_x;
  char _text[256];
  size_t _text_len;
  size_t _text_pos;
  uint8_t scroll_count;

public:
  M5TextScroll();
  void setCusor(int32_t x, int32_t y, uint8_t scroll_pixel);
  void setBgColor(uint32_t color);
  void setTextColor(uint32_t color);
  void setTextFont(const lgfx::IFont* font);
  void setText(const char* text);
  void showTextScroll();
  uint8_t getScrollCount();
};