R"JSS2(
// generiereString: Generates the single macro roster string line from form inputs
function generiereString() {
    const nummer = document.getElementById('lokNummer').value.trim();
    const bezeichnung = document.getElementById('lokBezeichnung').value.trim();
    if (!nummer) {
        alert('Please enter a DCC address or variable label!');
        return '';
    }
    let funcParts = [];
    for (let i = 0; i < totalFunctions; i++) {
        let text = document.getElementById(`func_text_${i}`).value.trim();
        let isStar = document.getElementById(`func_star_${i}`).checked;
        if (text === '') {
            funcParts.push('');
        } else {
            let prefix = isStar ? '*' : '';
            funcParts.push(`${prefix}${text}`);
        }
    }
    const resultString = `ROSTER(${nummer},"${bezeichnung}","${funcParts.join('/')}/")`;
    document.getElementById('outputString').value = resultString;
    return resultString;
}
// fuelleLokSelector: Populates the locomotive dropdown selection list with loaded data
function fuelleLokSelector() {
    const selector = document.getElementById('lokSelector');
    selector.innerHTML = '';
    aktualisiereAnzeigeZaehler();
    if (gesammelteRosterZeilen.length === 0) {
        selector.innerHTML = '<option value="">-- No locomotives loaded yet --</option>';
        return;
    }
    const defaultOpt = document.createElement('option');
    defaultOpt.value = "";
    defaultOpt.text = "-- Please select a locomotive --";
    selector.appendChild(defaultOpt);
    gesammelteRosterZeilen.forEach((line, index) => {
        const match = line.match(rosterRegex);
        if (match) {
            const addr = match[1];
            const id = match[2];
            const opt = document.createElement('option');
            opt.value = index;
            opt.text = `Address: ${addr} - ID: ${id}`;
            selector.appendChild(opt);
        }
    });
}
// waehleLokAusListe: Selects a locomotive from the dropdown roster list to display it
function waehleLokAusListe(index) {
    if (index === "") return;
    parseUndSetzeRoster(gesammelteRosterZeilen[index]);
}
// loescheLokAusListe: Deletes the currently highlighted locomotive out of the tracking list array
function loescheLokAusListe() {
    const selector = document.getElementById('lokSelector');
    const index = selector.value;
    if (index === "") {
        alert('Please select a locomotive from the dropdown first to delete it!');
        return;
    }
    const selectedText = selector.options[selector.selectedIndex].text;
    const confirmDelete = confirm(`Are you sure you want to delete "${selectedText}" from the roster list?`);
    if (confirmDelete) {
        gesammelteRosterZeilen.splice(index, 1);
        document.getElementById('inputString').value = gesammelteRosterZeilen.join('\n');
        fuelleLokSelector();
        if (gesammelteRosterZeilen.length > 0) {
            selector.value = 0;
            waehleLokAusListe(0);
        } else {
            resetFormular();
        }
        alert(`Locomotive "${selectedText}" was successfully deleted.`);
    }
}
// ladeDateiVomPC: Loads file entries directly from the user's computer via File API
function ladeDateiVomPC(event) {
    const file = event.target.files[0];
    if (!file) return;
    aktuellerDateiname = file.name;
    document.getElementById('fileNameInput').value = aktuellerDateiname;
    document.getElementById('activeFileInfo').innerText = `Active file: ${aktuellerDateiname}`;
    const reader = new FileReader();
    reader.onload = function(e) {
        const content = e.target.result;
        gesammelteRosterZeilen = content.split('\n')
            .map(line => line.trim())
            .filter(line => line.length > 0 && rosterRegex.test(line));
        document.getElementById('inputString').value = gesammelteRosterZeilen.join('\n');
        fuelleLokSelector();
        if (gesammelteRosterZeilen.length > 0) {
            document.getElementById('lokSelector').value = "0";
            parseUndSetzeRoster(gesammelteRosterZeilen[0]);
        }
    };
    reader.readAsText(file);
}
// parseUndSetzeRoster: Parses a raw text macro config line and applies configurations to input fields
function parseUndSetzeRoster(line) {
    const match = line.match(rosterRegex);
    if (!match) return;
    const nummer = match[1];
    const bezeichnung = match[2];
    let funcsString = match[3];
    if (funcsString.endsWith('/')) {
        funcsString = funcsString.slice(0, -1);
    }
    document.getElementById('lokNummer').value = nummer;
    document.getElementById('lokBezeichnung').value = bezeichnung;
    const parts = funcsString.split('/');
    for (let i = 0; i < totalFunctions; i++) {
        let textInput = document.getElementById(`func_text_${i}`);
        let starCheckbox = document.getElementById(`func_star_${i}`);
        if (i < parts.length) {
            let val = parts[i];
            if (val.startsWith('*')) {
                starCheckbox.checked = true;
                val = val.substring(1);
            } else {
                starCheckbox.checked = false;
            }
            textInput.value = val;
        } else {
            textInput.value = '';
            starCheckbox.checked = false;
        }
    }
    generiereString();
}
// anhaengeAnDatei: Appends or updates the active roster configuration string in the document stack
function anhaengeAnDatei() {
    const neuerString = generiereString();
    if (!neuerString) return;
    const aktNummer = document.getElementById('lokNummer').value.trim();
    let manuellerInhalt = document.getElementById('inputString').value.trim();
    if (manuellerInhalt) {
        gesammelteRosterZeilen = manuellerInhalt.split('\n')
            .map(line => line.trim())
            .filter(line => line.length > 0 && rosterRegex.test(line));
    }
    let gefundeneIndex = -1;
    for (let i = 0; i < gesammelteRosterZeilen.length; i++) {
        const testMatch = gesammelteRosterZeilen[i].match(rosterRegex);
        if (testMatch && testMatch[1] === aktNummer) {
            gefundeneIndex = i;
            break;
        }
    }
    if (gefundeneIndex !== -1) {
        gesammelteRosterZeilen[gefundeneIndex] = neuerString;
        alert(`Asset ${aktNummer} already existed and was updated in the list.`);
    } else {
        gesammelteRosterZeilen.push(neuerString);
        alert(`Asset ${aktNummer} was appended as a new line.`);
    }
    document.getElementById('inputString').value = gesammelteRosterZeilen.join('\n');
    fuelleLokSelector();
    speichereDateiDirekt(gesammelteRosterZeilen.join('\n') + '\n');
}
// speichereDateiDirekt: Saves the tracked configuration directly by serving a virtual file download
function speichereDateiDirekt(inhalt) {
    let customFilename = document.getElementById('fileNameInput').value.trim();
    if (!customFilename) {
        customFilename = 'myRoster.h';
    }
    const blob = new Blob([inhalt], { type: 'text/plain;charset=utf-8' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = customFilename;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
}
// speichereAlsNeueTxt: Saves current data fields into a freshly formatted file download structure
function speichereAlsNeueTxt() {
    let gesamtInhalt = document.getElementById('inputString').value.trim();
    if (!gesamtInhalt) {
        gesamtInhalt = generiereString();
        if (gesamtInhalt) {
            document.getElementById('inputString').value = gesamtInhalt;
        }
    }
    if (!gesamtInhalt) {
        alert('Please generate or enter a roster entry first!');
        return;
    }
    gesammelteRosterZeilen = gesamtInhalt.split('\n')
        .map(line => line.trim())
        .filter(line => line.length > 0 && rosterRegex.test(line));
    fuelleLokSelector();
    speichereDateiDirekt(gesammelteRosterZeilen.join('\n') + '\n');
    alert('Complete roster saved as a new file!');
}
// resetFormular: Resets all web form layout fields back to their clean initial state values
function resetFormular() {
    document.getElementById('lokNummer').value = '3';
    document.getElementById('lokBezeichnung').value = '3#EL3';
    for (let i = 0; i < totalFunctions; i++) {
        let textInput = document.getElementById(`func_text_${i}`);
        let starCheckbox = document.getElementById(`func_star_${i}`);
        if (i === 0) {
            textInput.value = 'Light';
            starCheckbox.checked = false;
        } else if (i === 1) {
            textInput.value = 'Bell';
            starCheckbox.checked = false;
        } else if (i === 2) {
            textInput.value = 'Horn';
            starCheckbox.checked = true;
        } else {
            textInput.value = '';
            starCheckbox.checked = false;
        }
    }
    document.getElementById('outputString').value = '';
    document.getElementById('inputString').value = '';
    document.getElementById('fileInput').value = '';
    gesammelteRosterZeilen = [];
    fuelleLokSelector();
    aktualisiereAnzeigeZaehler();
    aktuellerDateiname = "myRoster.h";
    document.getElementById('fileNameInput').value = aktuellerDateiname;
    document.getElementById('activeFileInfo').innerText = "No file loaded (Default: myRoster.h)";
    generiereString();
}
// kopiereInZwischenablage: Copies the active layout macro string into the OS clipboard buffer securely
function kopiereInZwischenablage() {
    let outputValue = document.getElementById('outputString').value;
    if (!outputValue) {
        outputValue = generiereString();
    }
    navigator.clipboard.writeText(outputValue).then(() => {
        alert('Roster line copied to clipboard!');
    }).catch(err => {
        console.error('Could not copy text: ', err);
        const output = document.getElementById('outputString');
        output.select();
        document.execCommand('copy');
        alert('Roster line copied to clipboard!');
    });
}

//window.onload = function() {
    initFunctionsGrid();
    generiereString();
    fuelleLokSelector();

window.ladeDateiVomPC = ladeDateiVomPC;
window.waehleLokAusListe = waehleLokAusListe;
window.loescheLokAusListe = loescheLokAusListe;
window.generiereString = generiereString;
window.resetFormular = resetFormular;
window.kopiereInZwischenablage = kopiereInZwischenablage;
window.speichereAlsNeueTxt = speichereAlsNeueTxt;
window.anhaengeAnDatei = anhaengeAnDatei;

//};

)JSS2"


/*
async function copyToClipboard(text) {
  // 1. Try the modern Clipboard API first
  if (navigator.clipboard && window.isSecureContext) {
    try {
      await navigator.clipboard.writeText(text);
      console.log('Copied using Clipboard API');
      return true;
    } catch (err) {
      console.warn('Clipboard API failed, trying fallback...', err);
    }
  }

  // 2. Fallback Mechanism (for older browsers or non-HTTPS environments)
  return fallbackCopyTextToClipboard(text);
}

function fallbackCopyTextToClipboard(text) {
  // Create a temporary textarea element
  const textArea = document.createElement('textarea');
  textArea.value = text;
  
  // Avoid scrolling to the bottom of the page when appending
  textArea.style.position = 'fixed';
  textArea.style.top = '0';
  textArea.style.left = '0';
  textArea.style.width = '2em';
  textArea.style.height = '2em';
  textArea.style.padding = '0';
  textArea.style.border = 'none';
  textArea.style.outline = 'none';
  textArea.style.boxShadow = 'none';
  textArea.style.background = 'transparent';

  document.body.appendChild(textArea);
  
  // Select the text inside the element
  textArea.focus();
  textArea.select();

  let successful = false;
  try {
    // Execute the old copy command
    successful = document.execCommand('copy');
    if (successful) {
      console.log('Copied using fallback mechanism');
    } else {
      console.error('Fallback copy command was unsuccessful');
    }
  } catch (err) {
    console.error('Fallback mechanism failed entirely', err);
  }

  // Clean up and remove the element from the DOM
  document.body.removeChild(textArea);
  return successful;
}
*/