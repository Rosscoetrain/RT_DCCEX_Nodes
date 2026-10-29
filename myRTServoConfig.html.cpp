/*
 *
 * @file myRTServoConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTSERVOCONFIG_HTML_CPP
#define MYRTSERVOCONFIG_HTML_CPP


#if defined(DCCEX_NODE_SERVO) || defined(DCCEX_NODE_NANO_SERVO)
#include <Arduino.h>

extern const char myRTServoConfig_html[]=R"HTML(

<style>
/* --- Tooltip CSS Component --- */
.tooltip-wrapper {
  position: relative;
  display: block; /* Forces vertical stacking */
  max-width: 40%; /* width: 100%;    Spans full form width */
}

/* The Tooltip Bubble */
.tooltip-wrapper::after {
  content: attr(data-tooltip);
  position: absolute;
  bottom: 125%;
  left: 50%;
  transform: translateX(-50%) scale(0.9);
  background: var(--panel, #222);
  color: var(--text, #fff);
  border: 1px solid var(--accent, #555);
  padding: 8px 12px;
  border-radius: 6px;
  font-size: 0.85rem;
  font-family: sans-serif;
  white-space: pre-wrap;
  width: max-content;
  max-width: 280px;
  z-index: 10;
  opacity: 0;
  pointer-events: none;
  transition: opacity 0.15s ease, transform 0.15s ease;
  box-shadow: 0 4px 12px rgba(0,0,0,0.5);
}

/* Tiny Arrow indicator */
.tooltip-wrapper::before {
  content: '';
  position: absolute;
  bottom: 110%;
  left: 50%;
  transform: translateX(-50%);
  border: 6px solid transparent;
  border-top-color: var(--accent, #555);
  z-index: 10;
  opacity: 0;
  pointer-events: none;
  transition: opacity 0.15s ease;
}

/* Show with animation on Hover or Focus */
.tooltip-wrapper:hover::after,
.tooltip-wrapper:hover::before,
.tooltip-wrapper:focus-within::after,
.tooltip-wrapper:focus-within::before {
  opacity: 1;
  pointer-events: auto;
}

/* Reset scale back to normal on active states */
.tooltip-wrapper:hover::after,
.tooltip-wrapper:focus-within::after {
  transform: translateX(-50%) scale(1);
}

/* --- Form Layout CSS Components --- */
.nvs-editor {
  position: relative;
  padding-top: 50px; /* Space so elements don't overlap absolute button */
  max-width: 100%;   /* max-width: 400px; Clean width boundary for stacked structures */
}

/* Absolute positioning for the defaults button */
.nvs-editor .btn-restore-defaults {
  position: absolute;
  top: 10px;
  right: 10px;
  font: inherit;
  cursor: pointer;
}

.nvs-editor .form-group {
  margin-bottom: 15px; /* Added breathing room for stacked layout */
}

.nvs-editor label {
  display: block;
  margin-bottom: 6px;
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

/* Input & Select widths changed to 100% to span the stacked wrapper container cleanly */
.nvs-editor .RT-input {
  width: 100%;
  box-sizing: border-box;
  font: inherit;
  margin-bottom: 4px;
  padding: 6px;
}
.nvs-editor .RT-output-select {
  width: 100%;
  box-sizing: border-box;
  font: inherit;
  margin-bottom: 4px;
  padding: 6px;
}
.nvs-editor .RT-label {
  display: block; /* Changed from inline widths to block level stacking */
  width: 39%;
  margin-bottom: 4px;
  font-weight: bold;
}

/* Form action button alignment */
.nvs-editor .form-group button {
  margin-top: 6px;
  display: block;
  width: 40%;         /*width: 100%; */
  padding: 6px;
}


/* The dim overlay covering the full screen */
.confirm-overlay {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.5);
  display: flex;
  justify-content: center; /* Horizontal center */
  align-items: center;     /* Vertical center */
  z-index: 9999;
}

/* The popup box */
.confirm-box {
  padding: 24px;
  border-radius: 8px;
  background: var(--panel, #222);
  color: var(--text, #fff);
  border: 1px solid var(--accent, #555);
  box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
  text-align: center;
  min-width: 300px;
  max-width: 90%;
}

/* Utility class to hide the modal */
.hidden {
  display: none !important;
}

/* Button layout styling */
.confirm-buttons {
  margin-top: 20px;
  display: flex;
  justify-content: flex-end;
  gap: 12px;
}

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


R"JSS(
<script>
(function() {

function saveBaseAddressOnly() {
  const baseAddress = parseInt(document.getElementById("baseAddress").value.trim());
  if (!baseAddress) {
      setStatus("Please enter a Base Address.", "red");
      return;
  }
  setStatus("Saving Base Address...", "orange");

  NVSTable[0] = baseAddress;
  saveNvsValues();
}

function setStatus(text, color) {
  const statusDiv = document.getElementById("status");
  statusDiv.style.color = color;
  statusDiv.innerText = text;
}

function loadNvsValue(nvs) {
  return NVSTable[nvs] ?? 0;
}

function loadSelectNvsValues(i) {
  let offset = (i - 1) * 4;
  let activePos = loadNvsValue(offset + 1);
  let inactivePos = loadNvsValue(offset + 2);
  let profile = loadNvsValue(offset + 3);
  let description = loadNvsValue(offset + 4);

  document.getElementById("activePos").value = activePos;
  document.getElementById("inactivePos").value = inactivePos;
  document.getElementById("profile").value = profile;
  document.getElementById("description").value = description;
}

function showCustomConfirm(message) {
  return new Promise((resolve) => {
    const overlay = document.getElementById('custom-confirm-overlay');
    const messageEl = document.getElementById('custom-confirm-message');
    const okBtn = document.getElementById('confirm-ok-btn');
    const cancelBtn = document.getElementById('confirm-cancel-btn');
    messageEl.textContent = message;
    overlay.classList.remove('hidden');
    function close(result) {
      overlay.classList.add('hidden');
      okBtn.removeEventListener('click', onOk);
      cancelBtn.removeEventListener('click', onCancel);
      resolve(result);
    }
    function onOk() { close(true); }
    function onCancel() { close(false); }
    okBtn.addEventListener('click', onOk);
    cancelBtn.addEventListener('click', onCancel);
  });
}


async function restoreDefaults() {
  setStatus("Restoring Factory Defaults", "orange");
  const confirmAction = await showCustomConfirm("Are you sure you want to restore all NVS to their default settings?");
  if (confirmAction) {
    NVSTable[0] = 1;
    for (let i = 1; i <= 16;i++) {
      NVSTable[1 + (i - 1) * 4] = 250;
      NVSTable[2 + (i - 1) * 4] = 150;
      NVSTable[3 + (i - 1) * 4] = 3;
      NVSTable[4 + (i - 1) * 4] = "Turnout " + i;
      document.getElementById("outputNum").value = 1;
      document.getElementById("activePos").value = NVSTable[1];
      document.getElementById("inactivePos").value = NVSTable[2];
      document.getElementById('profile').selectedIndex = NVSTable[3];
      document.getElementById("description").value = NVSTable[4];
    }
    console.log("Defaults restored successfully.");
    saveNvsValues();
    setStatus("Factory Defaults Restored", "green");
  } else {
  setStatus("", "black");
  }
}

// Initialise the 16 layout outputs
for (let i = 1; i <= 16; i++) {
  let opt = document.createElement("option");
  opt.value = i;
  opt.innerText = "Servo " + i;
  document.getElementById("outputNum").appendChild(opt);
  NVSBootNeeded[1 + (i - 1) * 4] = true;
  NVSBootNeeded[2 + (i - 1) * 4] = true;
  NVSBootNeeded[3 + (i - 1) * 4] = true;
  NVSBootNeeded[4 + (i - 1) * 4] = true;
}

document.getElementById("outputNum").value = 1;
loadSelectNvsValues(1);

// Event Bindings
document.getElementById("outputNum").addEventListener('change', function() {
  let currentNvs = parseInt(document.getElementById("outputNum").value, 10);
  console.log("currenNvs " + currentNvs);
  loadSelectNvsValues(currentNvs);
});

document.getElementById("activePos").addEventListener('change', function() {
  let currentNvs = parseInt(document.getElementById("outputNum").value, 10);
  NVSTable[1 + (currentNvs - 1) * 4] = parseInt(document.getElementById("activePos").value, 10);
  window.setConfigPanelDirty(true);
});

document.getElementById("inactivePos").addEventListener('change', function() {
  let currentNvs = parseInt(document.getElementById("outputNum").value, 10);
  NVSTable[2 + (currentNvs - 1) * 4] = parseInt(document.getElementById("inactivePos").value, 10);
  window.setConfigPanelDirty(true);
});

document.getElementById("profile").addEventListener('change', function() {
  let currentNvs = parseInt(document.getElementById("outputNum").value, 10);
  NVSTable[3 + (currentNvs - 1) * 4] = parseInt(document.getElementById("profile").value, 10);
  window.setConfigPanelDirty(true);
});

document.getElementById("description").addEventListener('input', function() {
  let currentNvs = parseInt(document.getElementById("outputNum").value, 10);
  NVSTable[4 + (currentNvs - 1) * 4] = document.getElementById("description").value;
  window.setConfigPanelDirty(true);
});

// Setup baseline interface fields
  setStatus(" ", "black");
  NVSBootNeeded[0] = true;

  document.getElementById("baseAddress").value = NVSTable[0];
  document.getElementById("outputNum").value = 1;
  document.getElementById("activePos").value = NVSTable[1];
  document.getElementById("inactivePos").value = NVSTable[2];
  document.getElementById('profile').selectedIndex = NVSTable[3];
  document.getElementById("description").value = NVSTable[4];

// Define the tooltip array with id matching criteria
  const tooltips = [
    { id: 'base', text: 'Set the base address for your DCC-EX node.' },
    { id: 'servo', text: 'Choose the servo (1 to 16) to configure.'},
    { id: 'activePos', text: 'Set the throw position travel limit active/thrown.'},
    { id: 'inactivePos', text: 'Set the closed position travel limit inactive/closed.'},
    { id: 'profile', text: 'Select the movement speed profile or physics behaviour for the servo motor hardware.'},
    { id: 'description', text: 'Enter a description for this turnout (optional).'}
  ];

// Map tooltips onto the custom wrapper elements instead of the inputs directly
  tooltips.forEach(item => {
    const wrapper = document.getElementById(`wrapper-${item.id}`);
    if (wrapper) {
      wrapper.setAttribute('data-tooltip', item.text);
    }
  });


  window.saveBaseAddressOnly = saveBaseAddressOnly;
  window.restoreDefaults = restoreDefaults;
  window.setStatus = setStatus;
})();

</script>


)JSS";



/*
NOTES:

NVSTable[]
0 = base address
1 = Servo 1 active position    100 - 500
2 = Servo 1 inactive position  100 - 500
3 = Servo 1 profile            Instant = 0, Fast = 1, Medium = 2, Slow = 3, Bounce = 4
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


#endif // MYRTSERVOCONFIG.HTML_CPP
#endif
