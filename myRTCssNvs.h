/*
 *
 * @file myRTCSSNvs.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTCSSNVS_H
#define MYRTCSSNVS_H

R"CSSNVS(
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
.nvs-editor .RT-select {
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
  border-bottom: 2px solid #ccc;
  padding-bottom: 5px;
}

/* Form action button alignment */
.nvs-editor .form-group button {
  margin-top: 6px;
  display: block;
  width: 40%;         /*width: 100%; */
  padding: 6px;
}
)CSSNVS"

#endif // MYRTCSSNVS_H