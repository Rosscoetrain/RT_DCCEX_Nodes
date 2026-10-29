/*
 *
 * @file myRTKatoConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#if defined(DCCEX_NODE_KATO) || defined(DCCEX_NODE_NANO_KATO)

#ifndef MYRTKATOCONFIG.HTML_CPP
#define MYRTKATOCONFIG.HTML_CPP

#include <Arduino.h>

extern const char myRTKatoConfig_html[]=R"???(

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

    #help_link a {
      color: white;
      text-decoration: none;
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
        <input class="RT-input" type="number" id="baseAddress" min="1" max="32760" placeholder="e.g., 1000">
        <button class="btn-secondary" onclick="saveBaseAddressOnly()">Save Base Address Only</button>
    </div>

    <div class="form-group">
        <label class="RT-label" for="outputNum">Board Output:</label>
        <select class="RT-output-select" id="outputNum" onchange="">
            <!-- Generated dynamically via JS for 1-8 -->
        </select>
    </div>

    <div class="form-group">
        <label class="RT-label" for="outputPulse">Output Pulse Length (10 - 10000mS):</label>
        <input class="RT-input" type="number" id="outputPulse" min="10" max="10000" placeholder="100">
    </div>

    <div class="form-group">
        <label class="RT-label" for="description">Description:</label>
        <input class="RT-input" type="text" id="description" placeholder="e.g Coal Yard Turnout">
    </div>

    <div id="status"></div>
    <div id="help_link">For help see the <a href="https://rosscoe.com/shop/index.php?main_page=page&id=5" target="new">Operating Manual</a></div>

</div>

<script>
(function() {

  function saveBaseAddressOnly() {
    const baseAddress = parseInt(document.getElementById("baseAddress").value.trim());
    if (isNaN(baseAddress) || baseAddress < 1 || baseAddress > 32760 ) {
        setStatus("Please enter a Base Address, between 1 and 32760.", "red");
        return;
    }
    setStatus("Saving Base Address...", "orange");

    for (let i=0; i<8; i++) {
      NVSTable[(i * 2)] = baseAddress + i;
    }
    saveNvsValues();
    setStatus("", "black");

    const confirmAction = confirm("The node needs to be restarted for this setting to take effect\nDo you want to restart now?");
    
    if (confirmAction) {
      setStatus("Restarting Node", "orange");
    }
  }


  function setStatus(text, color) {
    const statusDiv = document.getElementById("status");
    statusDiv.style.color = color;
    statusDiv.innerText = text;
  }

  function saveCurrentNvsValue(nvs, value) {
    NVSTable[nvs] = value;
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
    const confirmAction = await showCustomConfirm("Are you sure you want to restore all NVSs to their default settings?");
    
    if (confirmAction) {
      NVSTable[0] == 1;

      document.getElementById("baseAddress").value = NVSTable[0];
      for (let i = 1; i <= 8;i++)
       {
        NVSTable[1 + (i - 1) * 2] = 100;
        NVSTable[2 + (i - 1) * 2] = "Turnout " + i;
        document.getElementById("outputNum").value = 1;
        document.getElementById("outputPulse").value = NVSTable[1];
        document.getElementById("description").value = NVSTable[2];
        console.log("Defaults restored successfully.");
       }
      for (let i = 17; i <= 255;i++)
       {
        NVSTable[i] = 0;
       }
    saveNvsValues();
    } else {
    setStatus("", "black");
    }
  }

  for (let i = 1; i <= 8; i++) {
    let opt = document.createElement("option");
    opt.value = i;
    opt.innerText = "Output " + i;
    document.getElementById("outputNum").appendChild(opt)
    NVSBootNeeded[1 + (i - 1) * 2] = true;
    NVSBootNeeded[2 + (i - 1) * 2] = true;
  }

  document.getElementById("outputNum").addEventListener('change', function() {
    currentNvs = parseInt(document.getElementById("outputNum").value, 10);
    document.getElementById("outputPulse").value = NVSTable[1 + (currentNvs - 1) * 2];
    document.getElementById("description").value = NVSTable[2 + (currentNvs - 1) * 2];
  });

  document.getElementById("baseAddress").addEventListener('change', function() {
    NVSTable[0] = parseInt(document.getElementById("baseAddress").value.trim());
    window.setConfigPanelDirty(true);
  });

  document.getElementById("outputPulse").addEventListener('change', function() {
    const outputPulse = parseInt(document.getElementById("outputPulse").value, 10);
    if (outputPulse > 250) {
      setStatus("Warning this pulse time (>250mS) needs to be used with caution on solenoid turnouts.", "orange");
    } else {
      setStatus("&nbsp;", "black");
    }
    saveCurrentNvsValue(1 + (currentNvs - 1) * 2, outputPulse);
    window.setConfigPanelDirty(true);
  });

  document.getElementById("description").addEventListener('input', function() {
    NVSTable[2 + (currentNvs - 1) * 2] = document.getElementById("description").value;
    window.setConfigPanelDirty(true);
  });

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



  setStatus("&nbsp;", "black");
  NVSBootNeeded[0] = true;

  document.getElementById("baseAddress").value = NVSTable[0];
  document.getElementById("outputNum").value = 1;
  document.getElementById("outputPulse").value = NVSTable[1];
  document.getElementById("description").value = NVSTable[2];
  let currentNvs = 1;

  window.restoreDefaults = restoreDefaults;
  window.setStatus = setStatus;
})();

</script>
)???";

#endif // MYRTKATOCONFIG.HTML_CPP
#endif
