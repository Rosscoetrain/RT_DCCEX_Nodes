/*
 *
 * @file myRTCssCustomConfirm.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTCSSCUSTOMCONFIRM_H
#define MYRTCSSCUSTOMCONFIRM_H

R"CSSCUSTOMCONFIRM(
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

/* flex container for columns */
.servo-flex-container {
  display: flex;
  gap: 10px;
  margin-top: 50px;
  border: 2px solid #5F5F5F;
}

.servo-column {
  flex: 1;
  display: flex;
  flex-direction: column;
  border: 1px;
}

.main-servo-label {
  font-weight: bold;
  font-size: 1.2em;
  border-bottom: 2px solid #ccc;
  padding-bottom: 5px;
  width: 100%;
}

.control-buttons {
  margin-top: 20px;
  display: flex;
  justify-content: flex-start;
  gap: 12px;
}

.cb {
  border: 2px solid #ccc;
}

)CSSCUSTOMCONFIRM"

#endif // MYRTCSSCUSTOMCONFIRM_H