/*
 *
 * @file myRTSignalConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#if defined(DCCEX_NODE_SIGNAL) || defined(DCCEX_NODE_NANO_SIGNAL)

#ifndef MYRTSIGNALCONFIG.HTML_CPP
#define MYRTSIGNALCONFIG.HTML_CPP

#include <Arduino.h>

extern const char myRTSignalConfig_html[]=R"???(

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

    <!-- Top Right Corner Button -->
    <button class="btn-secondary btn-restore-defaults" onclick="restoreDefaults()">Restore Defaults</button>

    <div class="form-group">
        <label class="RT-label" for="baseAddress">Base Address:</label>
        <input class="RT-input" type="number" id="baseAddress" min="1" max="5000" placeholder="e.g., 1000">
        <button class="btn-secondary" onclick="saveBaseAddressOnly()">Save Base Address Only</button>
    </div>

    <div class="form-group">
        <label class="RT-label" for="outputNum">Signal Output:</label>
        <select class="RT-output-select" id="outputNum" onchange="">
            <!-- Generated dynamically via JS for 1-8 -//-//>
        </select>
    </div>

    <div id="status"></div>
    <div id="help_link"><a href="https://rosscoe.com/shop/index.php?main_page=page&id=5" target="new">Help</a></div>

</div>

<script>
  (function() {
  function saveBaseAddressOnly() {
    const baseAddress = document.getElementById("baseAddress").value.trim();
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

  function saveCurrentNvsValue(nvs, value) {
    NVSTable[nvs] = value;
  }

  function loadNvsValue(nvs) {
    console.log("nvs : " + nvs);
    return NVSTable[nvs] ?? 0;
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
      document.getElementById("baseAddress").value = NVSTable[0];

      console.log("Defaults restored successfully.");
      saveNvsValues();
      setStatus("Factory Defaults Restored", "green");
    } else {
    setStatus("", "black");
    }

  }

  for (let i = 1; i <= 8; i++) {
    let opt = document.createElement("option");
    opt.value = i;
    opt.innerText = "Output " + i;
    document.getElementById("outputNum").appendChild(opt)
  }

// Define the tooltip array with id matching criteria
  const tooltips = [
    { id: 'base', text: 'Set the base address for your DCC-EX node.' },
    { id: 'output', text: 'Choose the output (1 to 8) to configure.'},
    { id: 'pulseTime', text: 'Set a pulse time between 10ms and 10,000ms. Values over 250ms require caution with solenoid turnouts.'},
    { id: 'description', text: 'Enter a description for this turnout (optional).'}
  ];

// Map tooltips onto the custom wrapper elements instead of the inputs directly
  tooltips.forEach(item => {
    const wrapper = document.getElementById(`wrapper-${item.id}`);
    if (wrapper) {
      wrapper.setAttribute('data-tooltip', item.text);
    }
  });


  
  document.getElementById("outputNum").value = 1;

    document.getElementById("outputNum").addEventListener('change', function() {
      currentNvs = parseInt(document.getElementById("outputNum").value, 10);
    });

    setStatus("&nbsp;", "black");
    document.getElementById("baseAddress").value = NVSTable[0];
    document.getElementById("outputNum").value = 1;

    const currentNvs = parseInt(document.getElementById("outputNum").value, 10);

    window.restoreDefaults = restoreDefaults;
    window.setStatus = setStatus;
  })();

</script>
)???";


/*
NOTES:

NVSTable[]
0 = base address
1 = Signal 1 Type
2 = Signal 2 Type
3 = Signal 3 Type
4 = Signal 4 Type
5 = Signal 5 Type
6 = Signal 6 Type
7 = Signal 7 Type
8 = Signal 8 Type
9 = 
10 = 
11 = 
12 = 
13 = 
14 = 
15 = 
16 = 

*/


#endif // MYRTSIGNALCONFIG.HTML_CPP
#endif
