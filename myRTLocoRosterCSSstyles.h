R"CSS1(
:root {
    --bg-color: #121212;
    --card-bg: #1e1e1e;
    --primary: #3498db;
    --secondary: #95a5a6;
    --accent: #2980b9;
    --success: #27ae60;
    --success-hover: #219653;
    --danger: #e74c3c;
    --danger-hover: #c0392b;
    --warning: #f39c12;
    --text-color: #e0e0e0;
    --text-muted: #aaaaaa;
    --border-color: #333333;
    --input-bg: #2b2b2b;
    --grid-bg: #181818;
    /* DCC-EX Colors */
    --dccex-bg: #133940;
    --dccex-cyan: #00A3B8;
}

body {
    font-family: Arial, sans-serif;
    background-color: var(--bg-color);
    color: var(--text-color);
    margin: 0;
    padding: 20px;
}

.container {
    max-width: 1000px;
    margin: 0 auto;
    background: var(--card-bg);
    padding: 30px;
    border-radius: 8px;
    box-shadow: 0 4px 20px rgba(0,0,0,0.5);
    border: 1px solid var(--border-color);
}

h1, h2 {
    color: #ffffff;
    border-bottom: 2px solid var(--primary);
    padding-bottom: 8px;
    margin-top: 0;
}

.main-title {
    display: flex;
    align-items: center;
    gap: 10px;
    flex-wrap: wrap;
}

.dccex-badge {
    font-family: 'Segoe UI', Roboto, Helvetica, Arial, sans-serif;
    font-weight: 800;
    letter-spacing: 0.5px;
    font-size: 0.85em;
    display: inline-flex;
    align-items: center;
    background-color: var(--dccex-bg);
    border-radius: 4px;
    padding: 2px 8px;
    line-height: 1.2;
}

.dccex-badge .dcc-part {
    color: #ffffff;
}

.dccex-badge .ex-part {
    color: var(--dccex-cyan);
}

.section {
    margin-bottom: 25px;
    padding: 20px;
    background: var(--card-bg);
    border: 1px solid var(--border-color);
    border-radius: 6px;
}

.form-row {
    display: flex;
    gap: 20px;
    margin-bottom: 15px;
}

.form-group {
    flex: 1;
    display: flex;
    flex-direction: column;
}

label {
    font-weight: bold;
    margin-bottom: 5px;
    color: var(--text-muted);
    display: block;
}

input[type="text"], textarea, select {
    padding: 8px 12px;
    border: 1px solid var(--border-color);
    border-radius: 4px;
    font-size: 14px;
    background-color: var(--input-bg);
    color: #ffffff;
    box-sizing: border-box;
}

input:focus, textarea:focus, select:focus {
    outline: none;
    border-color: var(--primary);
    box-shadow: 0 0 5px rgba(52, 152, 219, 0.5);
}

.functions-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(280px, 1fr));
    gap: 12px;
    max-height: 450px;
    overflow-y: auto;
    padding: 5px;
    border: 1px solid var(--border-color);
    background: var(--grid-bg);
    border-radius: 4px;
}

.func-item {
    display: flex;
    align-items: center;
    background: var(--input-bg);
    padding: 6px 10px;
    border: 1px solid var(--border-color);
    border-radius: 4px;
    gap: 10px;
}

.func-label {
    font-weight: bold;
    min-width: 35px;
    color: var(--primary);
}

.func-item input[type="text"] {
    flex: 1;
    padding: 4px 8px;
    background-color: #333333;
    color: #ffffff;
    border: 1px solid #444;
}

.func-moment {
    display: flex;
    align-items: center;
    font-size: 12px;
    cursor: pointer;
    user-select: none;
    color: var(--warning);
    font-weight: bold;
}

.func-moment input {
    margin-right: 3px;
    accent-color: var(--warning);
    cursor: pointer;
}

.btn {
    background-color: var(--primary);
    color: white;
    border: none;
    padding: 10px 16px;
    font-size: 14px;
    border-radius: 4px;
    cursor: pointer;
    transition: background 0.2s;
}

.btn:hover {
    background-color: var(--accent);
}

.btn-success {
    background-color: var(--success);
}

.btn-success:hover {
    background-color: var(--success-hover);
}

.btn-danger {
    background-color: var(--danger);
}

.btn-danger:hover {
    background-color: var(--danger-hover);
}

.button-group-row {
    display: flex;
    gap: 10px;
    margin-top: 10px;
}

.button-group-row .btn {
    flex: 1;
}

.file-upload-wrapper {
    position: relative;
    overflow: hidden;
    display: inline-block;
}

.file-upload-wrapper input[type=file] {
    font-size: 100px;
    position: absolute;
    left: 0;
    top: 0;
    opacity: 0;
    cursor: pointer;
}

.custom-file-btn {
    background-color: #444444;
    color: white;
    padding: 8px 16px;
    border-radius: 4px;
    display: inline-block;
    font-size: 14px;
    font-weight: bold;
    cursor: pointer;
    border: 1px solid #555;
}

.custom-file-btn:hover {
    background-color: #555555;
}

textarea.output-box-full {
    width: 100%;
    max-width: 100%;
    height: 70px;
    font-family: monospace;
    font-size: 13px;
    resize: vertical;
    background-color: var(--input-bg);
    color: #ffffff;
    box-sizing: border-box;
}

textarea.roster-full-box {
    width: 100%;
    max-width: 100%;
    height: 150px;
    font-family: monospace;
    font-size: 13px;
    resize: vertical;
    background-color: var(--input-bg);
    color: #ffffff;
    white-space: pre;
    overflow-x: auto;
    box-sizing: border-box;
}

.import-export-area {
    display: flex;
    gap: 20px;
}

.import-export-area > div {
    flex: 1;
}

.hint {
    font-size: 12px;
    color: var(--text-muted);
    margin-top: 4px;
}

.backup-hint {
    font-size: 11px;
    color: var(--warning);
    margin-top: 4px;
    line-height: 1.4;
}

.file-box {
    background: var(--input-bg);
    padding: 15px;
    border-radius: 4px;
    border: 1px solid var(--border-color);
    display: flex;
    justify-content: space-between;
    align-items: center;
}

.file-info-area {
    display: flex;
    flex-direction: column;
    justify-content: center;
}

.active-file-info {
    font-size: 13px;
    color: var(--success);
    font-weight: bold;
}

.entry-count-info {
    font-size: 12px;
    color: var(--text-muted);
    margin-top: 4px;
}

.lok-selector-box {
    background: #252525;
    padding: 12px;
    border-radius: 4px;
    border: 1px solid var(--border-color);
    margin-bottom: 15px;
}

.selector-controls {
    display: flex;
    gap: 10px;
    margin-top: 5px;
}

.selector-controls select {
    flex: 1;
}

.btn-inline-danger {
    background-color: var(--danger);
    color: white;
    border: none;
    padding: 8px 14px;
    font-size: 13px;
    border-radius: 4px;
    cursor: pointer;
    white-space: nowrap;
}

.btn-inline-danger:hover {
    background-color: var(--danger-hover);
}
)CSS1"
