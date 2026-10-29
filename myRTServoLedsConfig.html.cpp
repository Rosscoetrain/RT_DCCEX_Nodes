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

#ifndef MYRTSERVOLEDSCONFIG_HTML_CPP
#define MYRTSERVOLEDSCONFIG_HTML_CPP

#include <Arduino.h>

extern const char myRTServoLedsConfig_html[]=R"???(

<div class="nvs-editor">
  <style>
    .nvs-editor {
      position: relative;
      padding-top: 40px; /* Added spacing so form elements don't overlap the absolute button */
    }
    
    .nvs-editor .btn-restore-defaults {
      position: absolute;
      top: 10px;
      right: 10px;
      font: inherit;
      cursor: pointer;
    }

    .nvs-editor .form-group {
      margin-bottom: 10px;
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
      box-sizing: border-box;
      font: inherit;
      margin-bottom: 4px;
    }
    .nvs-editor .RT-output-select {
      width: 30%;
      box-sizing: border-box;
      font: inherit;
      margin-bottom: 4px;
    }
    .nvs-editor .RT-label {
      width: 28%;
      margin-bottom: 4px;
      font-weight: bold;
    }
    .matrix-table {
      border-collapse: collapse;
      background-color: #ffffff;
      box-shadow: 0 2px 4px rgba(0,0,0,0.1);
      border-radius: 8px;
      overflow: hidden;
    }
    .matrix-table th {
      background-color: #f1f1f1;
      color: #333;
      font-weight: bold;
      padding: 12px;
      border-bottom: 2px solid #ddd;
      text-align: center;
    }
    .matrix-table th.row-header-label {
      text-align: left;
      min-width: 100px;
    }
    .matrix-table td {
      padding: 10px 12px;
      border-bottom: 1px solid #eee;
      text-align: center;
    }
    .matrix-table td.row-label {
      font-weight: bold;
      text-align: left;
      background-color: #fcfcfc;
      border-right: 1px solid #eee;
    }
    .radio-cell {
      cursor: pointer;
    }
    .radio-cell input {
      cursor: pointer;
      transform: scale(1.1);
    }
  </style>

  <!-- Top Right Corner Button -->
  <button class="btn-secondary btn-restore-defaults" onclick="restoreDefaults()">Restore Defaults</button>

  <!-- Table structure for perfect column alignment -->
  <table class="matrix-table">
    <thead>
      <tr id="header-row">
      <!-- Top-left corner blank cell -->
        <th class="row-header-label">Outputs</th>
        <!-- Column headers will be generated here -->
      </tr>
    </thead>
    <tbody id="matrix-body">
      <!-- 16 Data rows will be generated here -->
    </tbody>
  </table>

  <div id="status"></div>
  <div id="help_link"><a href="https://rosscoe.com/shop/index.php?main_page=page&id=5" target="new">Help</a></div>

</div>

<script>
  (function() {
    const baseNvs = 130;
    const headerRow = document.getElementById('header-row');
    const matrixBody = document.getElementById('matrix-body');
    const logBox = document.getElementById('log-box');

//  Generate Column Headers dynamically from array
    const colName = ["Input", "On/Off", "Flash", "Strobe", "Double Strobe", "Rotating"];

    const colLen = colName.length;

    for (let col = 0; col < colLen; col++) {
      const th = document.createElement('th');
      th.textContent = colName[col];
      headerRow.appendChild(th);
    }

//  Generate rows (Servo 1 .. Servo 16)
    for (let rowId = 0; rowId < 16; rowId++) {
      const checkedValue = NVSTable[baseNvs + rowId];

//    Create table row
      const tr = document.createElement('tr');

//    Create the left column label
      const tdLabel = document.createElement('td');
      tdLabel.className = 'row-label';
      tdLabel.textContent = `Servo ${rowId + 1}`;
      tr.appendChild(tdLabel);

//    Generate the 6 radio cells for this row
      for (let radioVal = 1; radioVal <= colLen; radioVal++) {
        const tdRadio = document.createElement('td');
        tdRadio.className = 'radio-cell';

        const radio = document.createElement('input');
        radio.type = 'radio';
        radio.name = `nvs_row_${rowId}`;
        radio.value = radioVal;

//      Store row metadata
        radio.dataset.rowId = rowId;

//      Pre-check the element if it matches the current array state
        if (radioVal === checkedValue) {
          radio.checked = true;
        }

        tdRadio.appendChild(radio);
        tr.appendChild(tdRadio);
      }

      matrixBody.appendChild(tr);
    }

//  Centralized Event Listener (Event Delegation)
    matrixBody.addEventListener('change', (event) => {
      if (event.target && event.target.tagName === 'INPUT') {
        const radio = event.target;
        const clickedRowId = parseInt(radio.dataset.rowId, 10) + baseNvs;
        const selectedValue = parseInt(radio.value, 10);
        if (NVSTable[clickedRowId]) {
          NVSTable[clickedRowId] = selectedValue;
          window.setConfigPanelDirty(true);
        }
      }
    });

    function restoreDefaults() {
      setStatus("Restoring Factory Defaults", "orange");
      const confirmAction = confirm("Are you sure you want to restore all NVS to their default settings?");
    
      if (confirmAction) {
        for (let i = 0; i < 16;i++) {
          NVSTable[baseNvs + i] = 1;
          document.querySelector(`input[name="nvs_row_${i}"][value="1"]`).checked = true;
        }
        saveNvsValues();
        
        setStatus("Factory Defaults Restored", "green");
      }
    }

    function setStatus(text, color) {
      const statusDiv = document.getElementById("status");
      statusDiv.style.color = color;
      statusDiv.innerText = text;
    }

    window.restoreDefaults = restoreDefaults;
    window.setStatus = setStatus;
  })();

</script>


)???";


/*
NOTES:

NVSTable[]

offset for leds
Servo 1 = NVS[130]
Servo 2 = NVS[131]
...

*/

#endif // MYRTSERVOLEDSCONFIG.HTML_CPP
#endif
