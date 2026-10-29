/*
 *
 * @file myRTLocoRosterConfig.html.cpp
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTLOCOROSTERCONFIG_HTML_CPP
#define MYRTLOCOROSTERCONFIG_HTML_CPP


extern const char myRTLocoRosterConfig_html[]=R"HEAD(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Model Railway Roster Editor for DCC-EX (Dark Mode)</title>
<style>
)HEAD"

#include "myRTLocoRosterCSSstyles.h"

R"HTML(
</style>
</head>
<body>
<div class="container">
    <h1>
        <span class="main-title">
            Model Railway Roster Editor for <span class="dccex-badge"><span class="dcc-part">DCC</span><span class="ex-part">-EX</span></span>
        </span>
    </h1>

    <!-- Locomotive Details -->
    <div class="section">
        <h2>Locomotive Details</h2>
        <!-- Dropdown to select loaded locomotives -->
        <div class="lok-selector-box" id="lokSelectorContainer">
            <label for="lokSelector">Select a loaded locomotive to edit or delete:</label>
            <div class="selector-controls">
                <select id="lokSelector" onchange="waehleLokAusListe(this.value)">
                    <option value="">-- No locomotives loaded yet --</option>
                </select>
                <button class="btn-inline-danger" onclick="loescheLokAusListe()">🗑 Delete Locomotive</button>
            </div>
        </div>

        <div class="form-row">
            <div class="form-group">
                <label for="lokNummer">DCC Address / Constant:</label>
                <input type="text" id="lokNummer" placeholder="e.g. 3 or LOC_3000" value="3">
            </div>
            <div class="form-group">
                <label for="lokBezeichnung">ID:</label>
                <input type="text" id="lokBezeichnung" placeholder="e.g. 3#EL3" value="3#EL3">
            </div>
        </div>
    </div>

    <!-- Decoder Functions -->
    <div class="section">
        <h2>Decoder Functions (F0 to F32)</h2>
        <p class="hint">Here you see all functions from F0 to F32. Empty fields create gaps in the roster string (e.g. <code>//</code>). Check the asterisk (*) for momentary functions.</p>
        <div class="functions-grid" id="functionsGrid"></div>
        <div style="margin-top: 10px;">
            <button class="btn" onclick="generiereString()">Generate Roster Line</button>
            <button class="btn btn-danger" onclick="resetFormular()">RESET</button>
        </div>
    </div>

    <!-- Import, Edit & Save -->
    <div class="section">
        <h2>Import, Edit & Save</h2>




        <div style="margin-bottom: 20px;">
            <label for="outputString">Generated Roster String (current loco):</label>
            <textarea id="outputString" class="output-box-full" placeholder="Click 'Generate Roster Line'..."></textarea>
        </div>

        <div class="import-export-area" style="margin-bottom: 20px;">
            <div>
                <div class="form-group" style="margin-bottom: 10px;">
                    <label for="fileNameInput">Filename for Download:</label>
                    <input type="text" id="fileNameInput" value="myRoster.h">
                    <div class="backup-hint">💡 <strong>Backup Notice:</strong> Change filename if needed (e.g. <code>myRoster_old.h</code>) before overwriting.</div>
                </div>
                <button class="btn btn-success" style="width: 100%; margin-top: 5px;" onclick="anhaengeAnDatei()">Append / Update Line in File</button>
                <div class="button-group-row">
                    <button class="btn" onclick="kopiereInZwischenablage()">Copy to Clipboard</button>
                    <button class="btn" onclick="speichereAlsNeueTxt()">Save as New File</button>
                </div>
            </div>
            <div>
                <label>Load Existing Roster File:</label>
                <div class="file-box">
                    <div class="file-info-area">
                        <div id="activeFileInfo" class="active-file-info">No file loaded (Default: myRoster.h)</div>
                        <div id="entryCountInfo" class="entry-count-info">Entries in file: 0</div>
                    </div>
                    <div class="file-upload-wrapper">
                        <button class="custom-file-btn">📁 Select File...</button>
                        <input type="file" id="fileInput" accept=".h,.txt" onchange="ladeDateiVomPC(event)">
                    </div>
                </div>
            </div>
        </div>

        <div style="margin-top: 15px;">
            <label for="inputString">Complete Roster Entries:</label>
            <textarea id="inputString" class="roster-full-box" placeholder='ROSTER(3,"3#EL3","Light/Bell/Horn/////////////////////////////////////////")'></textarea>
        </div>
    </div>
</div>
<script>
(function() {

)HTML"

// (3,"3#EL3","Light/Bell/Horn/////////////////////////////////////////")

#include "myRTLocoRosterJSapp_1.h"
#include "myRTLocoRosterJSapp_2.h"

R"END(
})();
</script>
</body>
</html>
)END";

#endif // MYRTLOCOROSTERCONFIG.HTML_H
