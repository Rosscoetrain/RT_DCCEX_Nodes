/*
 *
 * @file myRTEXTurntableConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTEXTURNTABLECONFIG_HTML_CPP
#define MYRTEXTURNTABLECONFIG_HTML_CPP

#ifdef DCCEX_NODE_NANO_EXTURNTABLE

#include <Arduino.h>

extern const char myRTTurntableConfig_html[]=R"HEAD(
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
    <label class="RT-label" for="base">Node Base Address:</label>
    <div class="tooltip-wrapper" id="wrapper-base">
      <input class="RT-input" type="number" id="base" min="1" max="32767" placeholder="e.g., 1000">
    </div>
    <button class="btn-secondary" onclick="saveBaseAddressOnly()">Save Base Address Only</button>
  </div>

  <div class="servo-flex-container">
  <!-- Column 1 -->
    <div class="servo-column">
      <div class="form-group">
        <label class="RT-label" for="trackNum">Turntable/traverser track:</label>
        <div class="tooltip-wrapper" id="wrapper-trackNum">
          <select class="RT-select" id="trackNum">
             <!-- Generated dynamically via JS for 1-48 -->
          </select>
        </div>
      </div>
    </div>

  <!-- Column 2 -->
    <div class="servo-column">
      <div class="form-group">
        <label class="RT-label" for="trackSteps">Track steps: </label>
        <div class="tooltip-wrapper" id="wrapper-trackSteps">
          <input class="RT-input" type="number" id="trackSteps" min="1" max="32767" placeholder="100">
        </div>
      </div>
      <div class="form-group">
          <label class="RT-label" for="description">Description:</label>
          <div class="tooltip-wrapper" id="wrapper-description">
            <input class="RT-input" type="text" id="description" placeholder="e.g Coal Yard Turnout">
          </div>
      </div>
    </div>
  </div>

  <div class="servo-flex-container">

    <div class="servo-column">

      <div class="form-group">
        <label class="RT-label" for="maximumspeed">Maximum Speed: </label>
        <div class="tooltip-wrapper" id="wrapper-maximumspeed">
          <input class="RT-input" type="number" id="maximumspeed" min="100" max="1000" placeholder="200">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="sanitysteps">Sanity Steps: </label>
        <div class="tooltip-wrapper" id="wrapper-sanitysteps">
          <input class="RT-input" type="number" id="sanitysteps" min="1" max="32767" placeholder="30000">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="phaseswitchangle">Phase Switching Angle</label>
        <div class="tooltip-wrapper" id="wrapper-phaseswitchangle">
          <input class="RT-input" type="number" id="phaseswitchangle" min="1" max="179" placeholder="25">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="ledslowflash">Led Slow Flash Rate</label>
        <div class="tooltip-wrapper" id="wrapper-ledslowflash">
          <input class="RT-input" type="number" id="ledslowflash" min="1" max="5000" placeholder="25">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="sensordebounce">Sensor Debounce</label>
        <div class="tooltip-wrapper" id="wrapper-sensordebounce">
          <input class="RT-input" type="number" id="sensordebounce" min="1" max="1000" placeholder="10">
        </div>
      </div>

    </div>

    <div class="servo-column">

      <div class="form-group">
        <label class="RT-label" for="acceleration">Acceleration: </label>
        <div class="tooltip-wrapper" id="wrapper-acceleration">
          <input class="RT-input" type="number" id="acceleration" min="1" max="100" placeholder="25">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="homesensitivity">Home Sensitivity: </label>
        <div class="tooltip-wrapper" id="wrapper-homesensitivity">
          <input class="RT-input" type="number" id="homesensitivity" min="1" max="1000" placeholder="600">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="gearingfactor">Gearing Factor</label>
        <div class="tooltip-wrapper" id="wrapper-gearingfactor">
          <input class="RT-input" type="number" id="gearingfactor" min="1" max="180" placeholder="45">
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="ledfastflash">Led Fast Flash Rate</label>
        <div class="tooltip-wrapper" id="wrapper-ledfastflash">
          <input class="RT-input" type="number" id="ledfastflash" min="1" max="5000" placeholder="25">
        </div>
      </div>


    </div>
  </div>
  <div class="servo-flex-container">

    <div class="servo-column">
      <div class="form-group">
        <label class="RT-label" for="operatingmode">Operating mode</label>
        <div class="tooltip-wrapper" id="wrapper-operatingmode">
          <select class="RT-select" id="operatingmode" name="operatingmode"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="phaseswitchmode">Phase Switch Mode</label>
        <div class="tooltip-wrapper" id="wrapper-phaseswitchmode">
          <select class="RT-select" id="phaseswitchmode" name="phaseswitchmode"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="invertstep">Invert Stepper Step pin</label>
        <div class="tooltip-wrapper" id="wrapper-invertstep">
          <select class="RT-select" id="invertstep" name="invertstep"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="invertdirection">Invert stepper direction pin</label>
        <div class="tooltip-wrapper" id="wrapper-invertdirection">
          <select class="RT-select" id="invertdirection" name="invertdirection"></select>
        </div>
      </div>

    </div>

    <div class="servo-column">
      <div class="form-group">
        <label class="RT-label" for="rotationmode">Rotation Mode</label>
        <div class="tooltip-wrapper" id="wrapper-rotationmode">
          <select class="RT-select" id="rotationmode" name="rotationmode"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="invertenable">Invert stepper enable pin</label>
        <div class="tooltip-wrapper" id="wrapper-invertenable">
          <select class="RT-select" id="invertenable" name="invertenable"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="stepperoutput">Stepper outputs active</label>
        <div class="tooltip-wrapper" id="wrapper-stepperoutput">
          <select class="RT-select" id="stepperoutput" name="stepperoutput"></select>
        </div>
      </div>

      <div class="form-group">
        <label class="RT-label" for="extraoutputs">Enable extra outputs</label>
        <div class="tooltip-wrapper" id="wrapper-extraoutputs">
          <select class="RT-select" id="extraoutputs" name="extraoutputs"></select>
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


)JSS1"

//java script variables need to go in the JSS1 section above

#include "myRTJssStandardFunctions.h"

//node specific functions go in the JSS2 section below

//after NVSTable[] = ; add applicable values for the defaults

R"JSS2(
  async function restoreDefaults() {
    setStatus("Restoring Factory Defaults", "orange");
    const confirmAction = await showCustomConfirm("Are you sure you want to restore all NVS to their default settings?");
    if (confirmAction) {
      NVSTable[0] = 600;
      NVSTable[1] = 1;
      NVSTable[2] = 2;
      NVSTable[3] = 3;
      NVSTable[4] = 8;
      NVSTable[5] = 17;
      NVSTable[6] = 7;
      NVSTable[7] = 9;
      NVSTable[8] = 10;
      NVSTable[9] = 18;
      NVSTable[10] = 21;
      NVSTable[11] = 38;
      NVSTable[12] = 47;
      NVSTable[13] = 200;
      NVSTable[14] = 25;
      NVSTable[15] = 0;
      NVSTable[16] = 30000;
      NVSTable[17] = 600;
      NVSTable[18] = 45;
      NVSTable[19] = 1;
      NVSTable[20] = 1;
      NVSTable[21] = 1;
      NVSTable[22] = 2;
      NVSTable[23] = 10;
      NVSTable[24] = 500;
      NVSTable[25] = 100;
      NVSTable[26] = 1;
      NVSTable[27] = 1;
      NVSTable[28] = 1;
      NVSTable[29] = 2;
      NVSTable[30] = 2;
      NVSTable[31] = 1;
      NVSTable[32] = 2;
      NVSTable[33] = 1;
      NVSTable[32001] = "";
      NVSTable[32002] = "";
      NVSTable[32003] = "RT_ESP32_Turntable";
      NVSTable[32004] = "rt-esp32";
      NVSTable[32005] = "RT-NODE-TURNTABLE";
      NVSTable[32009] = 0;

      for(let i = 0; i < 48; i++) {
        NVSTable[40 + i] = (i + 1) * 100;
        NVSTable[90 + i] = "Track " + (i + 1);
      }
      console.log("Defaults restored successfully.");
      saveNvsValues();
      setStatus("Factory Defaults Restored", "green");
    } else {
    setStatus("", "black");
    }
  }


// array with tooltips, nvs number, boot required and select type

  const tooltips = [
    { id: 'base', text: 'Set the base address for your DCC-EX node.', nvs: 0 , bootReq: true},
    { id: 'maximumspeed', text: 'Set the maximum speed for the stepper motor.', nvs: 13, bootReq: true},
    { id: 'acceleration', text: 'Set the acceleration for the stepper motor.', nvs: 14, bootReq: true},
    { id: 'sanitysteps', text: 'Maximum number of steps used for homing/calibration.', nvs: 16, bootReq: true},
    { id: 'homesensitivity', text: 'Minimum number of steps from home for homing/calibration.', nvs: 17, bootReq: true},
    { id: 'phaseswitchangle', text: 'Automatic phase switch angle in degrees.', nvs: 18, bootReq: true},
    { id: 'gearingfactor', text: 'Mechanical gearing factor for turntable.', nvs: 19, bootReq: true},
    { id: 'ledslowflash', text: 'The on/off time for the led slow flash rate mS.', nvs: 24, bootReq: true},
    { id: 'ledfastflash', text: 'The on/off time for the led fast flash rate mS.', nvs: 25, bootReq: true},
    { id: 'sensordebounce', text: 'Debounce delay for mechanical sensors in mS.', nvs: 23, bootReq: true},
    { id: 'operatingmode', text: 'Operating mode (Turntable or Traverser).', nvs: 26, bootReq: true, type: 'tttype'},
    { id: 'rotationmode', text: 'Select the perfered rotation mode.', nvs: 27, bootReq: true, type: 'direction'},
    { id: 'phaseswitchmode', text: 'Automatic or manual phase switch.', nvs: 28, bootReq: true, type: 'enable'},
    { id: 'invertdirection', text: 'Invert the stepper direction pin.', nvs: 29, bootReq: true, type: 'enable'},
    { id: 'invertstep', text: 'Invert the stepper step pin.', nvs: 30, bootReq: true, type: 'enable'},
    { id: 'invertenable', text: 'Invert the stepper enable pin.', nvs: 31, bootReq: true, type: 'enable'},
    { id: 'stepperoutput', text: 'Keep stepper outputs on at idle.', nvs: 32, bootReq: true, type: 'enable'},
    { id: 'extraoutputs', text: 'Enable the extra outputs.', nvs: 33, bootReq: true, type: 'enable'},
    { id: 'trackNum', text: 'Select a track to edit.'},
    { id: 'trackSteps', text: 'Enter the track steps for the stepper motor.'},
    { id: 'description', text: 'The description for this turntable/traverser track.'},
  ];

  setupTooltips(tooltips);


function loadNvsValue(nvs) {
  return NVSTable[nvs] ?? 0;
}

function loadSelectNvsValues(i) {
  let offset = 40 + (i - 1);
  let trackSteps = loadNvsValue(offset);
  let description = loadNvsValue(offset + 50);

  document.getElementById("trackSteps").value = trackSteps;
  document.getElementById("description").value = description;
}

// generate the track select options

for (let i = 1; i <= 48; i++) {
  let opt = document.createElement("option");
  opt.value = i;
  opt.innerText = "Track " + i;
  document.getElementById("trackNum").appendChild(opt);
  NVSBootNeeded[40 + (i - 1)] = true;
}

document.getElementById("trackNum").value = 1;
loadSelectNvsValues(1);

// event handler for the track select
document.getElementById("trackNum").addEventListener('change', function() {
  let currentNvs = parseInt(document.getElementById("trackNum").value, 10);
  console.log("currenNvs " + currentNvs);
  loadSelectNvsValues(currentNvs);
});



// Setup baseline interface fields
  setStatus(" ", "black");




)JSS2"

// this is the end of the jss and contains any functions that need to be added to the window

R"JSSEND(
  window.saveBaseAddressOnly = saveBaseAddressOnly;
  window.restoreDefaults = restoreDefaults;
  window.setStatus = setStatus;
  window.setupTooltips = setupTooltips;
})();

</script>
)JSSEND";



#endif

#endif // MYRTEXTURNTABLECONFIG_HTML_H



/* NOTES

|nvs| function                              | description                                                            | esp32-s3 default
| 0 | EX-Turntable address                  | Virtual pin (vpin) where the device is located                         | 1
| 1 | Step pin                              | Step/ pulse output pin                                                 | 1
| 2 | Direction pin                         | Direction output pin                                                   | 2
| 3 | Enable pin                            | Stepper driver enable pin                                              | 3
| 4 | Home sensor pin                       | Home sensor input pin                                                  | 8
| 5 | Limit sensor pin                      | Traverser limit input pin                                              | 17
| 6 | Relay pin                             | Track phase relay output pin                                           | 7
| 7 | LED pin                               | Status LED output pin                                                  | 9
| 8 | Accessory pin                         | Accessory output pin                                                   | 10
| 9  | Extra output pin 1                   | Outputs used by activity 10 - 11                                       | 18
| 10 | Extra output pin 2                   | Outputs used by activity 12 - 13                                       | 21
| 11 | Extra output pin 3                   | Outputs used by activity 14 - 15                                       | 38
| 12 | Extra output pin 4                   | Outputs used by activity 16 - 17                                       | 47
| 13 | Maximum speed                        | AccelStepper maximum speed                                             | 200
| 14 | Acceleration                         | AccelStepper acceleration                                              | 25
| 15 | Full-turn step count                 | Calibrated or configured full-turn steps                               | 0
| 16 | Sanity steps                         | Maximum number of steps used for homing/calibration                    | 30000
| 17 | Home sensitivity                     | Minimum number of steps from home                                      | 600
| 18 | Phase-switch angle                   | Automatic phase switch angle in degrees (1-179; zero uses the default) | 45
| 19 | Gearing factor                       | Mechanical gearing factor for turntable                                | 1
| 20 | Home sensor active state             | 1 = LOW, 2 = HIGH                                                      | 1
| 21 | Limit sensor active state            | 1 = LOW, 2 = HIGH                                                      | 1
| 22 | Relay active state                   | 1 = LOW, 2 = HIGH                                                      | 2
| 23 | Sensor debounce                      | Debounce time in milliseconds                                          | 10
| 24 | Slow LED interval                    | LED blink interval in milliseconds                                     | 500
| 25 | Fast LED interval                    | LED blink interval in milliseconds                                     | 100
| 26 | Operating mode                       | 1 = turntable, 2 = traverser                                           | 1
| 27 | Rotation mode                        | 1 = shortest path, 2 = forward only, 3 = reverse only                  | 1
| 28 | Phase switching mode                 | 1 = automatic, 2 = manual                                              | 1
| 29 | Invert direction                     | 1 = enabled, 2 = disabled                                              | 2
| 30 | Invert step                          | 1 = enabled, 2 = disabled                                              | 2
| 31 | Invert enable                        | 1 = enabled, 2 = disabled                                              | 1
| 32 | Keep stepper outputs enabled at idle | 1 = enabled, 2 = disabled                                              | 2
| 33 | Extra outputs enabled                | 1 = enabled, 2 = disabled                                              | 1

Boolean settings use 1/2 rather than 1/0 because the NVS table does not retain zero-valued entries.


| 40 | Track 1                              | Stepper position for track 1                                           | 100
| 41 | Track 2                              | Stepper position for track 2                                           | 200
| 42 | Track 3                              | Stepper position for track 3                                           | 300
| 43 | Track 4                              | Stepper position for track 4                                           | 400
| 44 | Track 5                              | Stepper position for track 5                                           | 500
| 45 | Track 6                              | Stepper position for track 6                                           | 600
| 46 | Track 7                              | Stepper position for track 7                                           | 700
| 47 | Track 8                              | Stepper position for track 8                                           | 800
| 48 | Track 9                              | Stepper position for track 9                                           | 900
| 49 | Track 10                             | Stepper position for track 10                                          | 1000
| 50 | Track 11                             | Stepper position for track 11                                          | 1100
| 51 | Track 12                             | Stepper position for track 12                                          | 1200
| 52 | Track 13                             | Stepper position for track 13                                          | 1300
| 53 | Track 14                             | Stepper position for track 14                                          | 1400
| 54 | Track 15                             | Stepper position for track 15                                          | 1500
| 55 | Track 16                             | Stepper position for track 16                                          | 1600
| 56 | Track 17                             | Stepper position for track 17                                          | 1700
| 57 | Track 18                             | Stepper position for track 18                                          | 1800
| 58 | Track 19                             | Stepper position for track 19                                          | 1900
| 59 | Track 20                             | Stepper position for track 20                                          | 2000
| 60 | Track 21                             | Stepper position for track 21                                          | 2100
| 61 | Track 22                             | Stepper position for track 22                                          | 2200
| 62 | Track 23                             | Stepper position for track 23                                          | 2300
| 63 | Track 24                             | Stepper position for track 24                                          | 2400
| 64 | Track 25                             | Stepper position for track 25                                          | 2500
| 65 | Track 26                             | Stepper position for track 26                                          | 2600
| 66 | Track 27                             | Stepper position for track 27                                          | 2700
| 67 | Track 28                             | Stepper position for track 28                                          | 2800
| 68 | Track 29                             | Stepper position for track 29                                          | 2900
| 69 | Track 30                             | Stepper position for track 30                                          | 3000
| 70 | Track 31                             | Stepper position for track 31                                          | 3100
| 71 | Track 32                             | Stepper position for track 32                                          | 3200
| 72 | Track 33                             | Stepper position for track 33                                          | 3300
| 73 | Track 34                             | Stepper position for track 34                                          | 3400
| 74 | Track 35                             | Stepper position for track 35                                          | 3500
| 75 | Track 36                             | Stepper position for track 36                                          | 3600
| 76 | Track 37                             | Stepper position for track 37                                          | 3700
| 77 | Track 38                             | Stepper position for track 38                                          | 3800
| 78 | Track 39                             | Stepper position for track 39                                          | 3900
| 79 | Track 40                             | Stepper position for track 40                                          | 4000
| 80 | Track 41                             | Stepper position for track 41                                          | 4100
| 81 | Track 42                             | Stepper position for track 42                                          | 4200
| 82 | Track 43                             | Stepper position for track 43                                          | 4300
| 83 | Track 44                             | Stepper position for track 44                                          | 4400
| 84 | Track 45                             | Stepper position for track 45                                          | 4500
| 85 | Track 46                             | Stepper position for track 46                                          | 4600
| 86 | Track 47                             | Stepper position for track 47                                          | 4700
| 87 | Track 48                             | Stepper position for track 48                                          | 4900

| 90 - 137 | Track 1 - 48                   | Description for track 1 to 48                                          | Track 1 - 48

*/