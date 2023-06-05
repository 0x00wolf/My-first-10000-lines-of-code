function countSelected(selectObject) {
    let numberSelected = 0;
    for (let i = 0; i < selectObject.options.length; i++) {
        if (selectObject.options[i].selected) {
            numberSelected++;
        }
    }
    return numberSelected;
}

function createParagraph(musicTypes) {
    const para = document.createElement("p");
    para.textContent = "You have selected " + musicTypes + " options(s).";
    document.body.appendChild(para);
}

const btn = document.getElementById("btn");

btn.addEventListener("click", () => {
    const musicTypes = document.selectForm.musicTypes;
    createParagraph(countSelected(musicTypes));
    console.log('You have selected ${countSelected(musicTypes)} options(s).');
});