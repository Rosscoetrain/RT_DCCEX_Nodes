/*
 *
 * @file myRTXingConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTXINGCONFIG_HTML_CPP
#define MYRTXINGCONFIG_HTML_CPP


#ifdef DCCEX_NODE_XING
#include <Arduino.h>

extern const char myRTXingConfig_html[]=R"HEAD(
<style>
)HEAD"

#include "myRTCssTooltips.h"

#include "myRTCssNvs.h"

#include "myRTCssCustomConfirm.h"


R"HTML(
</style>

<div id="custom-confirm-overlay" class="confirm-overlay hidden">
  <div id="custom-confirm-box" class="confirm-box">
    <p id="custom-confirm-message">Are you sure?</p>
    <div class="confirm-buttons">
      <button id="confirm-cancel-btn" class="btn btn-cancel">No</button>
      <button id="confirm-ok-btn" class="btn btn-ok">Yes</button>
    </div>
  </div>
</div>

<div class="nvs-editor">
  <!-- Top Right Corner Button -->
  <button class="btn-secondary btn-restore-defaults" onclick="restoreDefaults()">Restore Defaults</button>

  <div class="form-group">
    <label class="RT-label" for="baseAddress">Node Base Address:</label>
    <div class="tooltip-wrapper" id="wrapper-base">
      <input class="RT-input" type="number" id="baseAddress" min="1" max="32767" placeholder="e.g., 1000">
    </div>
    <button class="cb btn-secondary" onclick="saveBaseAddressOnly()">Save Base Address Only</button>
  </div>

  <!-- Side-by-Side Servo Container -->
  <div class="servo-flex-container">

    <!-- Servo 1 Column -->
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">Servo 1</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="activePos1">Active Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-activePos1">
          <input class="RT-input" type="number" id="activePos1" min="100" max="500" placeholder="250">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="inactivePos1">Inactive Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-inactivePos1">
          <input class="RT-input" type="number" id="inactivePos1" min="100" max="500" placeholder="150">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="profile1">Profile:</label>
        <div class="tooltip-wrapper" id="wrapper-profile1">
          <select class="RT-input" id="profile1">
            <option value="0">Instant</option>
            <option value="1">Fast</option>
            <option value="2">Medium</option>
            <option value="3">Slow</option>
            <option value="4">Bounce</option>
          </select>
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="description1">Description:</label>
        <div class="tooltip-wrapper" id="wrapper-description1">
          <input class="RT-input" type="text" id="description1" placeholder="e.g Coal Yard Turnout">
        </div>
      </div>
    </div>

    <!-- Servo 2 Column -->
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">Servo 2</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="activePos2">Active Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-activePos2">
          <input class="RT-input" type="number" id="activePos2" min="100" max="500" placeholder="250">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="inactivePos2">Inactive Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-inactivePos2">
          <input class="RT-input" type="number" id="inactivePos2" min="100" max="500" placeholder="150">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="profile2">Profile:</label>
        <div class="tooltip-wrapper" id="wrapper-profile2">
          <select class="RT-input" id="profile2">
            <option value="0">Instant</option>
            <option value="1">Fast</option>
            <option value="2">Medium</option>
            <option value="3">Slow</option>
            <option value="4">Bounce</option>
          </select>
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="description2">Description:</label>
        <div class="tooltip-wrapper" id="wrapper-description2">
          <input class="RT-input" type="text" id="description2" placeholder="e.g Coal Yard Turnout">
        </div>
      </div>
    </div>
  </div>

  <div class="servo-flex-container">
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 1} 0>`)">Close Servo 1</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 1} 1>`)">Throw Servo 1</button>
      </div>
    </div>
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 2} 0>`)">Close Servo 2</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 2} 1>`)">Throw Servo 2</button>
      </div>
    </div>
  </div>

  <!-- Side-by-Side LED Container -->
  <div class="servo-flex-container">
        
    <!-- LED 1 Column -->
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">LED 1</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="onTime1">On Time (ms):</label>
        <div class="tooltip-wrapper" id="wrapper-onTime1">
          <input class="RT-input" type="number" id="onTime1" min="0" max="10000" placeholder="e.g., 500">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="offTime1">Off Time (ms):</label>
          <div class="tooltip-wrapper" id="wrapper-offTime1">
            <input class="RT-input" type="number" id="offTime1" min="0" max="10000" placeholder="e.g., 500">
          </div>
          </div>
      </div>

    <!-- LED 2 Column -->
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">LED 2</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="onTime2">On Time (ms):</label>
        <div class="tooltip-wrapper" id="wrapper-onTime2">
          <input class="RT-input" type="number" id="onTime2" min="0" max="10000" placeholder="e.g., 500">
        </div>
      </div>
      <div class="form-group">
        <label class="RT-label" for="offTime2">Off Time (ms):</label>
        <div class="tooltip-wrapper" id="wrapper-offTime2">
          <input class="RT-input" type="number" id="offTime2" min="0" max="10000" placeholder="e.g., 500">
        </div>
      </div>
    </div>
  </div>

  <div class="servo-flex-container">
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 3} 0>`)">Led 1 off</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 3} 1>`)">Led 1 on</button>
      </div>
    </div>
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 4} 0>`)">Led 2 off</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 4} 1>`)">Led 2 on</button>
      </div>
    </div>
  </div>

  <div class="servo-flex-container">
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 5} 0>`)">Both Leds off</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 5} 1>`)">Both Leds on</button>
      </div>
    </div>
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 6} 0>`)">Leds stop flashing</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 6} 1>`)">Leds start flashing</button>
      </div>
    </div>
  </div>

  <div class="servo-flex-container">
    <div class="servo-column">
      <div class="control-buttons">
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 7} 0>`)">Auxillary off</button>
        <button class="cb" onclick="sendCommand(`<T ${NVSTable[0] + 7} 1>`)">Auxillary on</button>
      </div>
    </div>
    <div class="servo-column">
      <div class="control-buttons">
      </div>
    </div>
  </div>


  <div class="servo-flex-container">
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">Start delay</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="startDelay">Start delay (ms):</label>
        <div class="tooltip-wrapper" id="wrapper-startDelay">
          <input class="RT-input" type="number" id="startDelay" min="0" max="10000" placeholder="e.g., 500">
        </div>
      </div>
    </div>
    <div class="servo-column">
      <div class="form-group header-group">
        <label class="RT-label main-servo-label">Hold delay</label>
      </div>
      <div class="form-group">
        <label class="RT-label" for="holdDelay">Hold delay (ms):</label>
        <div class="tooltip-wrapper" id="wrapper-holdDelay">
          <input class="RT-input" type="number" id="holdDelay" min="0" max="10000" placeholder="e.g., 500">
        </div>
      </div>
    </div>
  </div>

  <div id="status"></div>
  <div id="help_link"><a href="https://rosscoe.com" target="new">Help</a></div>
</div>
)HTML"

R"JSS1(
<script>
(function() {

// Define the tooltip array with id matching criteria
  const tooltips = [
    { id: 'base', text: 'Set the base address for your DCC-EX node.' },
    { id: 'activePos1', text: 'Set the active (Thrown) position for servo 1 (100 - 500).' },
    { id: 'inactivePos1', text: 'Set the inactive (Close) position for servo 1 (100 - 500).' },
    { id: 'profile1', text: 'Set the movement profile for servo 1.' },
    { id: 'description1', text: 'Add a description for servo 1.' },
    { id: 'acivePos2', text: 'Set the active (Thrown) position for servo 2 (100 - 500).' },
    { id: 'inactivePos2', text: 'Set the inactive (Close) position for servo 2 (100 - 500).' },
    { id: 'profile2', text: 'Set the movement profile for servo 2.' },
    { id: 'description2', text: 'Add a description for servo 2.' },
    { id: 'onTime1', text: 'Set the on time for led 1 when flashing.' },
    { id: 'offTime1', text: 'Set the off time for led 1 when flashing.' },
    { id: 'onTime2', text: 'Set the on time for led 2 when flashing.' },
    { id: 'offTime2', text: 'Set the off time for led 2 when flashing.' },
    { id: 'startDelay', text: 'Set the time after leds start flashing before servos move.' },
    { id: 'holdDelay', text: 'Set the time after servos stop moving before leds stop flashing.' },
  ];

)JSS1"

//java script variables need to go in the JSS1 section above

#include "myRTJssStandardFunctions.h"

//node specific functions go in the JSS2 section below

//after NVSTable[0] = 1; add applicable values for the defaults

R"JSS2(
async function restoreDefaults() {
  setStatus("Restoring Factory Defaults", "orange");
  const confirmAction = await showCustomConfirm("Are you sure you want to restore all NVS to their default settings?");
  if (confirmAction) {
    NVSTable[0] = 1;
    NVSTable[1] = 150;
    NVSTable[2] = 500;
    NVSTable[3] = 0;
    NVSTable[4] = "Servo 1";
    NVSTable[5] = 150;
    NVSTable[6] = 500;
    NVSTable[7] = 0;
    NVSTable[8] = "Servo 2";
    NVSTable[9] = 1000;
    NVSTable[10] = 500;
    NVSTable[11] = 1000;
    NVSTable[12] = 500;
    NVSTable[13] = 2000;
    NVSTable[14] = 2000;
    NVSTable[32001] = "";
    NVSTable[32002] = "";
    NVSTable[32003] = "RT_ESP32_Xing";
    NVSTable[32004] = "rt-esp32";
    NVSTable[32005] = "RT-NODE-XING";
    NVSTable[32009] = 0;

    console.log("Defaults restored successfully.");
    saveNvsValues();
    setStatus("Factory Defaults Restored", "green");
  } else {
  setStatus("", "black");
  }
}

  document.getElementById("baseAddress").value = NVSTable[0];
  document.getElementById("activePos1").value = NVSTable[1];
  document.getElementById("inactivePos1").value = NVSTable[2];
  document.getElementById('profile1').selectedIndex = NVSTable[3];
  document.getElementById("description1").value = NVSTable[4];
  document.getElementById("activePos2").value = NVSTable[5];
  document.getElementById("inactivePos2").value = NVSTable[6];
  document.getElementById('profile2').selectedIndex = NVSTable[7];
  document.getElementById("description2").value = NVSTable[8];
  document.getElementById("onTime1").value = NVSTable[9];
  document.getElementById("offTime1").value = NVSTable[10];
  document.getElementById('onTime2').value = NVSTable[11];
  document.getElementById("offTime2").value = NVSTable[12];
  document.getElementById("startDelay").value = NVSTable[13];
  document.getElementById("holdDelay").value = NVSTable[14];



// Setup baseline interface fields
  setStatus(" ", "black");
  NVSBootNeeded[0] = true;
  NVSBootNeeded[1] = true;
  NVSBootNeeded[2] = true;
  NVSBootNeeded[3] = true;
  NVSBootNeeded[4] = true;
  NVSBootNeeded[5] = true;
  NVSBootNeeded[6] = true;
  NVSBootNeeded[7] = true;
  NVSBootNeeded[8] = true;
  NVSBootNeeded[9] = true;
  NVSBootNeeded[10] = true;
  NVSBootNeeded[11] = true;
  NVSBootNeeded[12] = true;
  NVSBootNeeded[13] = true;
  NVSBootNeeded[14] = true;


// event listeners

  document.getElementById("activePos1").addEventListener('change', function() {
    NVSTable[1] = parseInt(document.getElementById("activePos1").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("inactivePos1").addEventListener('change', function() {
    NVSTable[2] = parseInt(document.getElementById("inactivePos1").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("profile1").addEventListener('change', function() {
    NVSTable[3] = parseInt(document.getElementById("profile1").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("description1").addEventListener('input', function() {
    NVSTable[4] = document.getElementById("description1").value;
    window.setConfigPanelDirty(true);
  });



  document.getElementById("activePos2").addEventListener('change', function() {
    NVSTable[5] = parseInt(document.getElementById("activePos2").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("inactivePos2").addEventListener('change', function() {
    NVSTable[6] = parseInt(document.getElementById("inactivePos2").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("profile2").addEventListener('change', function() {
    NVSTable[7] = parseInt(document.getElementById("profile2").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("description2").addEventListener('input', function() {
    NVSTable[8] = document.getElementById("description2").value;
    window.setConfigPanelDirty(true);
  });

  document.getElementById("onTime1").addEventListener('change', function() {
    NVSTable[9] = parseInt(document.getElementById("onTime1").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("offTime1").addEventListener('change', function() {
    NVSTable[10] = parseInt(document.getElementById("offTime1").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("onTime2").addEventListener('change', function() {
    NVSTable[11] = parseInt(document.getElementById("onTime2").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("offTime2").addEventListener('change', function() {
    NVSTable[12] = parseInt(document.getElementById("offTime2").value, 10);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("startDelay").addEventListener('change', function() {
    NVSTable[13] = parseInt(document.getElementById("startDelay").value, 10);
    window.setConfigPanelDirty(true);
  });
  document.getElementById("holdDelay").addEventListener('change', function() {
    NVSTable[14] = parseInt(document.getElementById("holdDelay").value, 10);
    window.setConfigPanelDirty(true);
  });



)JSS2"

// this is the end of the jss and contains any functions that need to be added to the window

R"JSSEND(

  setupTooltips(tooltips);

  window.saveBaseAddressOnly = saveBaseAddressOnly;
  window.restoreDefaults = restoreDefaults;
  window.setStatus = setStatus;
  window.sendCommand = sendCommand;
})();

</script>
)JSSEND";



/*
NOTES:

NVSTable[]
0 = base address
1 = Servo 1 active position    100 - 500
2 = Servo 1 inactive position  100 - 500
3 = Servo 1 profile            Instant = 0, Fast = 1, Medium = 2, Slow = 3
4 = Servo 1 description        "A string value"

5 = Servo 2 active position    100 - 500
6 = Servo 2 inactive position  100 - 500
7 = Servo 2 profile            Instant = 0, Fast = 1, Medium = 2, Slow = 3
8 = Servo 2 description        "A string value"

9= Led 1 on time
10= Led 1 off time
11= Led 2 on time
12= Led 2 off time

13= Start delay
14= Hold delay

*/
#endif

#endif // MYRTXINGCONFIG_HTML_CPP