/*
 *
 * @file myRTServoConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#if defined(DCCEX_NODE_SERVO) || defined(DCCEX_NODE_NANO_SERVO)

#ifndef MYRTSERVOHELPCONFIG_HTML_CPP
#define MYRTSERVOHELPCONFIG_HTML_CPP

#include <Arduino.h>

extern const char myRTServoHelpConfig_html[]=R"???(

<div class="nvs-editor">
  <style>
    .nvs-editor {
      position: relative;
      padding-top: 40px; /* Added spacing so form elements don't overlap the absolute button */
    }
    
    /* Absolute positioning for the defaults button */
    .nvs-editor .btn-restore-defaults {
      position: absolute;
      top: 10px;
      right: 10px;
      font: inherit;
      cursor: pointer;
    }

    .nvs-editor label {
      display: block;
      margin-bottom: 4px;
      font-weight: bold;
    }
    .nvs-editor input,
    .nvs-editor select,
    .nvs-editor button {
      font: inherit;
    }

    #status { 
      margin-top: 15px; 
      font-weight: bold; 
      text-align: center;
    }
    
    .nvs-editor .RT-input {
      width: 30%;
      box-sizing: border-box; /* Ensures padding doesn't break the 50% width */
      font: inherit;
      margin-bottom: 4px;
    }
    .nvs-editor .RT-output-select {
      width: 30%;
      box-sizing: border-box; /* Ensures padding doesn't break the 50% width */
      font: inherit;
      margin-bottom: 4px;
    }
    .nvs-editor .RT-label {
      width: 25%;
      margin-bottom: 4px;
      font-weight: bold;
    }
  </style>

    <div id="help_text">
    <p>Future help text</p>
    </div>

    <div id="status"></div>
    <div id="help_link"><a href="https://rosscoe.com/shop/index.php?main_page=page&id=5" target="new">Help</a></div>

</div>

)???";


#endif // MYRTSERVOHELPCONFIG.HTML_CPP
#endif
