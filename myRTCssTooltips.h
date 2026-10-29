/*
 *
 * @file myRTCssTooltips.h
 *
 */

 /*
 *  © 2026 Ross Scanlon
 *
 */

#ifndef MYRTCSSTOOLTIPS_H
#define MYRTCSSTOOLTIPS_H

R"CSSTOOLTIPS(
/* --- Tooltip CSS Component --- */
.tooltip-wrapper {
  position: relative;
  display: block; /* Forces vertical stacking */
  max-width: 40%; /* width: 100%;    Spans full form width */
}

/* The Tooltip Bubble */
.tooltip-wrapper::after {
  content: attr(data-tooltip);
  position: absolute;
  bottom: 125%;
  left: 50%;
  transform: translateX(-50%) scale(0.9);
  background: var(--panel, #222);
  color: var(--text, #fff);
  border: 1px solid var(--accent, #555);
  padding: 8px 12px;
  border-radius: 6px;
  font-size: 0.85rem;
  font-family: sans-serif;
  white-space: pre-wrap;
  width: max-content;
  max-width: 280px;
  z-index: 10;
  opacity: 0;
  pointer-events: none;
  transition: opacity 0.15s ease, transform 0.15s ease;
  box-shadow: 0 4px 12px rgba(0,0,0,0.5);
}

/* Tiny Arrow indicator */
.tooltip-wrapper::before {
  content: '';
  position: absolute;
  bottom: 110%;
  left: 50%;
  transform: translateX(-50%);
  border: 6px solid transparent;
  border-top-color: var(--accent, #555);
  z-index: 10;
  opacity: 0;
  pointer-events: none;
  transition: opacity 0.15s ease;
}

/* Show with animation on Hover or Focus */
.tooltip-wrapper:hover::after,
.tooltip-wrapper:hover::before,
.tooltip-wrapper:focus-within::after,
.tooltip-wrapper:focus-within::before {
  opacity: 1;
  pointer-events: auto;
}

/* Reset scale back to normal on active states */
.tooltip-wrapper:hover::after,
.tooltip-wrapper:focus-within::after {
  transform: translateX(-50%) scale(1);
}

)CSSTOOLTIPS"


#endif // MYRTCSSTOOLTIPS_H