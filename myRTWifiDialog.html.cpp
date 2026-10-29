/*
 *
 * @file myRTWifiDialog.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#if defined(DCCEX_NODE_DUAL) || defined(DCCEX_NODE_KATO) || defined(DCCEX_NODE_SERVO) || defined(DCCEX_NODE_SIGNAL) || defined(DCCEX_NODE_NANO_DUAL) || defined(DCCEX_NODE_NANO_KATO) || defined(DCCEX_NODE_NANO_SERVO) || defined(DCCEX_NODE_NANO_SIGNAL)


#ifndef MYRTWIFIDIALOG_HTML_CPP
#define MYRTWIFIDIALOG_HTML_CPP

#include <Arduino.h>

extern const char myRTWifiDialog_html[]=R"HTML(

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

    <!-- Top Right Corner Button -->
    <button class="btn-secondary btn-restore-defaults" onclick="restoreDefaults()">Restore Defaults</button>

    <div class="form-group">
        <label class="RT-label" for="wifiSsid">WIFI ssid:</label>
        <input class="RT-input" type="text" id="wifiSsid" placeholder="DCCEX_xxxxxx">
        <label class="RT-label" for="wifiPassword">WIFI password:</label>
        <input class="RT-input" type="text" id="wifiPassword" placeholder="DCCEX_xxxxxx">
        <button class="btn-secondary" onclick="saveWifiDetailsOnly()">Save Wifi details Only</button>
    </div>
        <label class="RT-label" for="wifiHostname">Node Hostname:</label>
        <input class="RT-input" type="text" id="wifiHostname" placeholder="RTNODE_xxxxxx">
        <button class="btn-secondary" onclick="saveHostnameOnly()">Save Hostname Only</button>
    <div class="form-group">

    <div id="status"></div>
    <div id="help_link"><a href="https://rosscoe.com/shop/index.php?main_page=page&id=5" target="new">Help</a></div>

</div>
)HTML"

R"JSS(
<script>


function saveWifiDetailsOnly() {
  const wifiSsid = document.getElementById("wifiSsid").value.trim();
  const wifiPassword = document.getElementById("wifiPassword").value.trim();

  if (!wifiSsid) {
    setStatus("Please enter the WIFI ssid.", "red");
    return;
  }
  if (!wifiPassword) {
    setStatus("Please enter the WIFI password.", "red");
    return;
  }
// send <C WIFI "wifiSsid" "wifiPassword">
  setStatus("", "black");

  cmdInput.value = '<C WIFI "' + wifiSsid + '" "' + wifiPassword + '">';
  cmdWaiting = true;
}


function saveHostnameOnly() {
  const wifiHostname = document.getElementById("wifiHostname").value.trim();

  if (!wifiHostname) {
    setStatus("Please enter the Hostname.", "red");
    return;
  }

  cmdInput.value = '<C WIFI HOSTNAME "' + wifiHostname + '">';
  cmdWaiting = true;
}


  function setStatus(text, color) {
    const statusDiv = document.getElementById("status");
    statusDiv.style.color = color;
    statusDiv.innerText = text;
  }

  function restoreDefaults() {
    setStatus("Restoring Factory Defaults", "orange");
    const confirmAction = confirm("Are you sure you want to restore WIFI settings to their default settings?");
    
    if (confirmAction) {
      cmdInput.value = '<C WIFI "" "">';
      cmdWaiting = true;
      while (cmdWaiting) {}   // wait until previous completes
      cmdInput.value = '<C WIFI "RTNODE">';
      cmdWaiting = true;
    }
  }

  // Define the tooltip array with id matching criteria
  const tooltips = [
    { id: 'ssid', text: 'Set the wifi ssid.'},
    { id: 'password', text: 'Set the wifi password.'},
    { id: 'hostname', text: 'Set the decoder network hostname.'},
    { id: 'ap', text: 'Reset the decoder to AP only mode.'}
  ];

</script>
)JSS";

#endif // MYRTWIFIDIALOG.HTML_CPP
#endif
