/*
 *
 * @file myRTMasterConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTMASTERCONFIG_HTML_CPP
#define MYRTMASTERCONFIG_HTML_CPP


#ifdef DCCEX_NODE_MASTER
#include <Arduino.h>

extern const char myRTMasterConfig_html[]=R"HEAD(
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
        <div class="tooltip-wrapper"  id="wrapper-base">
          <input class="RT-input" type="number" id="baseAddress" min="1" max="32767" placeholder="e.g., 1000">
        </div>
        <button class="btn-secondary" onclick="saveBaseAddressOnly()">Save Base Address Only</button>
    </div>

    <div class="form-group">
        <label class="RT-label" for="outputNum">Board Output:</label>
        <div class="tooltip-wrapper" id="wrapper-servo">
          <select class="RT-output-select" id="outputNum">
              <!-- Generated dynamically via JS for 1-16 -->
          </select>
        </div>
    </div>

    <div class="form-group">
        <label class="RT-label" for="activePos">Active Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-activePos">
          <input class="RT-input" type="number" id="activePos" min="100" max="500" placeholder="250">
        </div>
    </div>

    <div class="form-group">
        <label class="RT-label" for="inactivePos">Inactive Position (100 - 500):</label>
        <div class="tooltip-wrapper" id="wrapper-inactivePos">
          <input class="RT-input" type="number" id="inactivePos" min="100" max="500" placeholder="150">
        </div>
    </div>

    <div class="form-group">
        <label class="RT-label" for="profile">Profile:</label>
        <div class="tooltip-wrapper" id="wrapper-profile">
          <select class="RT-input" id="profile">
              <option value="0">Instant</option>
              <option value="1">Fast</option>
              <option value="2">Medium</option>
              <option value="3">Slow</option>
              <option value="4">Bounce</option>
          </select>
        </div>
    </div>

    <div class="form-group">
        <label class="RT-label" for="description">Description:</label>
        <div class="tooltip-wrapper" id="wrapper-description">
          <input class="RT-input" type="text" id="description" placeholder="e.g Coal Yard Turnout">
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

    console.log("Defaults restored successfully.");
    saveNvsValues();
    setStatus("Factory Defaults Restored", "green");
  } else {
  setStatus("", "black");
  }
}

function loadSelectNvsValues(i) {
  let offset = (i - 1) * 4;
  let description = loadNvsValue(offset + 4);

  document.getElementById("description").value = description;
}

// Setup baseline interface fields
  setStatus(" ", "black");
  NVSBootNeeded[0] = true;

  document.getElementById("baseAddress").value = NVSTable[0];

)JSS2"

// this is the end of the jss and contains any functions that need to be added to the window

R"JSSEND(
  window.saveBaseAddressOnly = saveBaseAddressOnly;
  window.restoreDefaults = restoreDefaults;
  window.setStatus = setStatus;
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
...
  = Servo 16 active position
  = Servo 16 inactive position 
  = Servo 16 profile           

Subsequent servo NVSs are
active position   = 1 + (servo number - 1) * 4
inactive position = 2 + (servo number - 1) * 4
profile           = 3 + (servo number - 1) * 4
description       = 4 + (servo number - 1) * 4


*/
#endif

#endif // MYRTMASTERCONFIG_HTML_CPP