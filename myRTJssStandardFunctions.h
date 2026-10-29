/*
 *
 * @file myRTJssStandardFunctions.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTJSSSTANDARDFUNCTIONS_H
#define MYRTJSSSTANDARDFUNCTIONS_H

R"JSSSF(
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

const DROPDOWN_OPTIONS_1 = [
  { value: 1, text: 'enabled' },
  { value: 2, text: 'disabled' },
];

const DROPDOWN_OPTIONS_2 = [
  { value: 1, text: 'Shortest path' },
  { value: 2, text: 'Forward only' },
  { value: 3, text: 'Reverse only' },
];

const DROPDOWN_OPTIONS_3 = [
  { value: 1, text: 'Turntable' },
  { value: 2, text: 'Traverser' },
];

// Map option sets directly to the type names
const DROPDOWN_MAP = {
  enable: DROPDOWN_OPTIONS_1,
  direction: DROPDOWN_OPTIONS_2,
  tttype: DROPDOWN_OPTIONS_3,
};



function setupTooltips(tooltipsList) {
  tooltipsList.forEach((item) => {
    // Check if the nvs key exists and is not undefined/null (accepts 0)
    const hasNvs = item.nvs !== undefined && item.nvs !== null;

    // Only map boot requirement if nvs exists
    if (hasNvs && typeof NVSBootNeeded !== 'undefined') {
      NVSBootNeeded[item.nvs] = item.bootReq;
    }

    const element = document.getElementById(item.id);
    const wrapper = document.getElementById(`wrapper-${item.id}`);

    if (element) {
      // If the type matches an entry in DROPDOWN_MAP and element has no options yet
      if (DROPDOWN_MAP[item.type] && element.tagName.toLowerCase() === 'select' && element.options.length === 0) {
        DROPDOWN_MAP[item.type].forEach((opt) => {
          const optionEl = document.createElement('option');
          optionEl.value = opt.value;
          optionEl.textContent = opt.text;
          element.appendChild(optionEl);
        });
      }

      // Only assign value and attach NVSTable sync if nvs exists
      if (hasNvs) {
        element.value = NVSTable[item.nvs];

        element.addEventListener('change', function () {
          NVSTable[item.nvs] = parseInt(this.value, 10);
          if (typeof window.setConfigPanelDirty === 'function') {
            window.setConfigPanelDirty(true);
          }
        });
      }
    }

    // Tooltip wrapper attribute is still set regardless of nvs presence
    if (wrapper) {
      wrapper.setAttribute('data-tooltip', item.text);
    }
  });
}

function sendCommand(command) {
  console.log('Send command:', command);
  fetch('/parse', {
    method: 'POST',
    headers: { 'Content-Type': 'application/txt' },
    body: command
  })
  .then(response => {
    if (!response.ok) throw new Error('HTTP ' + response.status);
    return response.text();
  })
  .catch(err => console.error('Failed to save roster:', err));
  return command;
}

)JSSSF"

#endif // MYRTJSSSTANDARDFUNCTIONS_H