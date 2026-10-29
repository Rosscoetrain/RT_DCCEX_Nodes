
R"JSS1(
// totalFunctions: Max count of decoder functions (F0 to F32)
const totalFunctions = 33;
// gesammelteRosterZeilen: Collected roster lines / lines loaded from the file
let gesammelteRosterZeilen = [];
// aktuellerDateiname: Current filename for downloading or editing
let aktuellerDateiname = "myRoster.h";
// rosterRegex: Regular expression used to parse single ROSTER definitions
const rosterRegex = /^ROSTER\s*\(\s*([a-zA-Z0-9_\-]+)\s*,\s*"([^"]*)"\s*,\s*"([^"]*)"\s*\)/;
// initFunctionsGrid: Initializes the layout grid structure for F0-F32 on screen
function initFunctionsGrid() {
    const grid = document.getElementById('functionsGrid');
    grid.innerHTML = '';
    for (let i = 0; i < totalFunctions; i++) {
        const item = document.createElement('div');
        item.className = 'func-item';
        let defaultText = '';
        let defaultChecked = '';
        if (i === 0) defaultText = 'Light';
        if (i === 1) defaultText = 'Bell';
        if (i === 2) { defaultText = 'Horn'; defaultChecked = 'checked'; }
        item.innerHTML = `
            <span class="func-label">F${i}</span>
            <input type="text" id="func_text_${i}" value="${defaultText}" placeholder="Function for F${i}">
            <label class="func-moment" title="Momentary Function">
                <input type="checkbox" id="func_star_${i}" ${defaultChecked}> *
            </label>
        `;
        grid.appendChild(item);
    }
}
// aktualisiereAnzeigeZaehler: Updates the entry counter / display count label on the UI
function aktualisiereAnzeigeZaehler() {
    const count = gesammelteRosterZeilen.length;
    document.getElementById('entryCountInfo').innerText = `Entries in file: ${count}`;
}

    initFunctionsGrid();
    generiereString();
    fuelleLokSelector();

)JSS1"


