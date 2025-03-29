#include <LilyGo_AMOLED.h>
#include <LV_Helper.h>

LilyGo_AMOLED amoled;

lv_obj_t *mainLabel;
lv_style_t mainLabelStyle;

void setup()
{
  //
  // Initialize the serial port for debugging
  // Set the baud rate to 115200 for serial communication
  // This is useful for debugging and monitoring the program's output
  //

  Serial.begin(115200);


  //
  // Automatically determine the device type and initialize it
  //
  
  if (!amoled.begin()) {
      Serial.println("The board model cannot be detected, please raise the Core Debug Level 5 to debug");
      while (1) {
          delay(1000);
      }
  }


  //
  // Initialize LVGL
  // The LVGL library must be initialized after the display is initialized
  // and before the LVGL library is used.
  //

  beginLvglHelper(amoled,
                  true);


  //
  // Set the background color of the entire screen
  //

  lv_obj_set_style_bg_color(lv_scr_act(),
                            lv_color_black(),
                            LV_PART_MAIN);


  ///////////////////////////////////////////////////
  //
  // Initialize the style for the main label
  //
  //    - White, left aligned text
  //    - Black background
  //    - Transparent background
  //    - No scrolling
  //
  //////////////////////////////////////////////////

  lv_style_init(&mainLabelStyle);
  
  lv_style_set_text_color(&mainLabelStyle,
                          lv_color_white());

  lv_style_set_text_font(&mainLabelStyle,
                         &lv_font_montserrat_24);

  lv_style_set_text_align(&mainLabelStyle,
                          LV_TEXT_ALIGN_LEFT);  

  lv_style_set_bg_color(&mainLabelStyle,
                        lv_color_black());  

  lv_style_set_bg_opa(&mainLabelStyle,
                      LV_OPA_TRANSP);           

  lv_style_set_text_opa(&mainLabelStyle,
                        LV_OPA_COVER);


  //
  // Create a label object on the screen
  // The label is created on the screen and is used to display text
  // The label is created with the mainLabelStyle style
  // 
  
  mainLabel = lv_label_create(lv_scr_act());

  if (mainLabel == NULL) {
      Serial.println("Failed to create label object");
      return;
  }

  lv_obj_add_style(mainLabel,
                   &mainLabelStyle,
                   0);

  lv_obj_set_size(mainLabel,
                  amoled.width(),
                  amoled.height());

  lv_obj_set_pos(mainLabel,
                 0,
                 0);

  lv_label_set_recolor(mainLabel,
                      true);

  lv_label_set_text(mainLabel,
                    "Hello World!");

  
  return;
}


void loop()
{

  //
  // Handle LVGL tasks
  // This function must be called periodically to allow LVGL to update the display and handle events
  // It is typically called in the main loop of the program.
  // The delay time is set to the returned ms value to ensure smooth operation of the LVGL library
  //

  uint32_t delayTime = lv_task_handler();


  //
  // Delay for the returned ms period to allow the display to update
  //

  delay(delayTime);

  return;
}