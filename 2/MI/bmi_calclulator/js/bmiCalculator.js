function initBMICalculator() {
    setupInputDataChangeHandlers();
}

function setupInputDataChangeHandlers() {
    var weightInputField = getWeightInputField();
    weightInputField.addEventListener("keyup", updateBMI);
    
    var heightInputField = getHeightInputField();
    heightInputField.addEventListener("keyup", updateBMI);
}

function updateBMI() {
    var height = getHeightInputField().value;
    var weight = getWeightInputField().value;
    console.log("Updating BMI: " + height + " " + weight);
    
    var bmiValue = calculateBMI(height, weight);
    var formattedBMI = getFormattedBMI(bmiValue);
    var bmiColor = getBMIColorCode(bmiValue);
    
    updateHTML(bmiValue, formattedBMI, bmiColor);
}

function calculateBMI(height, weight) {
    var heightInMeters = height / 100.0;
    var bmi = weight / (heightInMeters * heightInMeters);
    var truncatedBMI = truncateDecimalsFromBMI(bmi);
    return truncatedBMI;
}

function truncateDecimalsFromBMI(bmi) {
    var bmiString = bmi.toString();
    if(bmiString.indexOf(".") > 0) {
        bmiString = bmiString.slice(0, (bmiString.indexOf(".")) + 3);
    }
    return bmiString;
}

function getFormattedBMI(bmiValue) {
    if (bmiValue < 16) {
        return "starkes Untergewicht";
    } else if (bmiValue < 17) {
        return "mäßiges Untergewicht";
    } else if (bmiValue < 18.5) {
        return "leichtes Untergewicht";
    } else if (bmiValue < 25) {
        return "Normalgewicht";
    } else if (bmiValue < 30) {
        return "Präadipositas ";
    } else if (bmiValue < 35) {
        return "Adipositas Grad I";
    } else if (bmiValue < 40) {
        return "Adipositas Grad II";
    } else {
        return "Adipositas Grad III";
    }
}

function getBMIColorCode(bmiValue) {
    if (bmiValue < 18.5) {
        return "warning";
    }
    if (bmiValue > 18.5 && bmiValue < 25) {
        return "ok";
    }
    if (bmiValue > 25) {
        return "warning";
    }
}

function updateHTML(bmiValue, formattedBMI, warningColor) {
    document.getElementById("bmi_result_value").innerHTML = bmiValue;
    var bmiResultText = document.getElementById("bmi_result_text");
    bmiResultText.innerHTML = formattedBMI;
    bmiResultText.className = warningColor;
}

function getWeightInputField() {
    return document.getElementById("input_field_weight")
}

function getHeightInputField() {
    return document.getElementById("input_field_height")
}