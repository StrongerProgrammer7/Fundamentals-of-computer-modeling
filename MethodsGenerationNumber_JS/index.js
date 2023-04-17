
let myChart;
Chart.register(ChartDataLabels);
document.addEventListener('DOMContentLoaded',(e)=>
{
   
    console.log('Dom loaded');
    myChart =  new Chart(document.getElementById('myChart').getContext('2d'), 
    {
    type: 'bar',
    plugins: [ChartDataLabels],
    options: {
      scales: {
      
        x:
        {
            type: 'linear',
            beginAtZero: true,
            offset: false,
            grid:
            {
                offset: false,
            },
            ticks: 
            {
                stepSize: 0.1
            },
            title:
            {
                display: true,
                text: 'Отрезки',
                font:
                {
                    size: 18,
                    weight: "bold"
                }
            },
           

        },
        y: {
          beginAtZero: true,
          title:
            {
                display: true,
                text: 'Количество',
                font:
                {
                    size: 18,
                    weight: "bold"
                }
            },
            ticks: 
            {
                stepSize: 1
            }
        }
      },
      plugins:
      {
        
        datalabels: 
        {
            display: function(context) {
                return context.dataset.data[context.dataIndex].y > 0;
              },
            formatter: function(value,context)
            {
                return value.y;
            },
            backgroundColor: function(context) 
            {
                return 'wheat';// return context.dataset.backgroundColor;
            },
              borderRadius: 4,
              color: 'black',
              font: 
              {
                weight: 'bold'
              },

              padding: 6
            
        },
           
       
            tooltip:
            {
                callbacks:
                {
                    title: (items)=>
                    {
                        if(!items.length)
                        {
                            return '';
                        }
                        const item = items[0];
                        const x = item.parsed.x;
                        const min = x - 0.05;
                        const max = x + 0.05;
                        return `Segments: ${min} - ${max}`;
                    }
                }
            },
       
        },
        
        
        
    }
    
  });
});

const x_vals = [0.05, 0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85,0.95];

function expectedValue(vector_random)
{
    let sum = 0.0;
    for(let i=0;i<vector_random.length;i++)
    {
        sum+=vector_random[i];
    }

    return sum / vector_random.length;
}

function dispersion(vector_random,expectedValue)
{
	let sum = 0;
	for (let i = 0; i < vector_random.length; i++)
		sum += (vector_random[i] - expectedValue) * (vector_random[i] - expectedValue);

	return sum / vector_random.length;
}

function standardDeviation(dispersion)
{
	return Math.sqrt(dispersion);
}

function cutNumber(posNumbers, number,start,end)
{
    let digits = Array.from(String(number)).map(i=>Number(i));
    
	let R3 = 0;
	let step = 1;
    for(let i=digits.length-1;i>=0 ;i--)
    {
        if (posNumbers > start && posNumbers <= end)
		{
			R3 += digits[i] * step;
			step *= 10;
		}
        if (String(R3).length==4)
			return R3;
        posNumbers--;
    }
	return R3;
}

function fillDataGrid(R0,R1,R3)
{
    let table = document.getElementById('dataTable').appendChild(document.createElement('tr'));
    let td = table.appendChild(document.createElement('td'));
    td.textContent = `${R0}`;
    td = table.appendChild(document.createElement('td'));
    td.textContent = `${R1}`;
    td = table.appendChild(document.createElement('td'));
    td.textContent = `${R3}`;
}

function fillDataGridExtra(method,expectedValue,dispersion,standartDeviation)
{
    let tr = document.getElementById(method);
        tr.childNodes[3].textContent = Math.round(parseFloat(expectedValue)*10000)/10000;
        tr.childNodes[5].textContent = Math.round(parseFloat(dispersion)*10000)/10000;
        tr.childNodes[7].textContent = Math.round(parseFloat(standartDeviation)*10000)/10000;
    
}

function fillIntervalLabel(method,expectedVal,dispersion,standardDeviation)
{
    let start = Math.round(parseFloat(Math.abs(expectedVal - standardDeviation))*10000)/10000;
    let end = Math.round(parseFloat(expectedVal + standardDeviation)*10000)/10000;
    let percent = (Math.abs(end - start))*100;
    percent = Math.round(parseFloat(percent)*100)/100;
    let interval = document.getElementById('intervalTest');
    switch (method) 
    {
        case 0:
             interval.childNodes[1].innerHTML = "Частотный тест метода 1: (" + String(start) +" ; " + String(end) +") " + String(percent) +"%";
            break;
        case 1:
            interval.childNodes[3].innerHTML = "Частотный тест метода 2: (" + String(start) +" ; " + String(end) +") " + String(percent)+"%";
            break;
        case 2:
            interval.childNodes[5].innerHTML = "Частотный тест метода 3: (" + String(start) +" ; " + String(end) +") " + String(percent)+"%";
            break;
        default:
            break;
    }
}

function clearDataGrid()
{
    let countNods = document.getElementById('dataTable').childElementCount;
    for(let i = 1;i<countNods;i++)
    {
        let child = document.getElementById('dataTable').lastChild; 
        document.getElementById('dataTable').removeChild(child);
    }
}

function methodOfMeanSquares(countPoints, R0)
{
	let randNumb = new Array();

	for (let i = 0; i < countPoints; i++)
	{
		let R1 = R0 * R0;

		let R3 = 0.0;
		if (R1 > 1000000)
			R3 = cutNumber(8, R1, 2, 6);
		else
			if (R1 > 100000)
				R3 = cutNumber(7, R1, 2, 6);
			else
				if (R1 > 10000)
					R3 = cutNumber(6, R1, 0, 5);
				else
					R3 = R1;
        //console.log(`R0 = ${R0}, R1 =${R1}, R3 = ${R3}`);
		 if(i<10)
		 	fillDataGrid(R0, R1, R3);
		R0 = R3;
		randNumb.push(R3/10000.0);
        
	}
   // console.log(randNumb);
	return randNumb;
}

function methodOfMult(countPoints, R0,R1)
{
	let randNumb = new Array();
	for (let i = 0; i < countPoints; i++)
	{
		let R3 = R0 * R1;
		let temp = 0.0;
		if (R3 > 1000000)
			temp = cutNumber(8, R3, 2, 6);
		else
			if (R3 > 100000)
				temp = cutNumber(7, R3, 2, 6);
			else
				if (R3 > 10000)
					temp = cutNumber(6, R3, 0, 5);
				else
					temp = R3;
		 if(i<10)
		 	fillDataGrid(R1, R3, temp);
		randNumb.push(temp / 10000.0);
		R1 = cutNumber(8, R3, 4, 8);
        //console.log(`R0 = ${R0}, R1 =${R1}, R3 = ${R3}`);
        
	}
	return randNumb;
}

function methodLinearCongruent(countPoints, multiplier, divisor)
{
	let randNumb = new Array();
	let temp = multiplier;
	for (let i = 0; i < countPoints; i++)
	{
		let R3 = multiplier * temp;
		 if(i<10)
		 	fillDataGrid(temp, R3, R3%divisor);
		randNumb.push((R3%divisor) / 10000.0);
       // console.log(`temp = ${temp}, R3 =${R3}, R3%div = ${R3%divisor}`);
		temp = R3 % divisor;
        
	}
	return randNumb;
}

function countPointBySegment(vector_randomPoints)
{
	let countPointByDiapason = new Array(0,0,0,0,0,0,0,0,0,0);

	for (let i = 0; i < vector_randomPoints.length; i++)
	{
		if (vector_randomPoints[i] > 0 && vector_randomPoints[i] < 0.1)
			countPointByDiapason[0]++;
		if (vector_randomPoints[i] >= 0.1 && vector_randomPoints[i] < 0.2)
			countPointByDiapason[1]++;
		if (vector_randomPoints[i] >= 0.2 && vector_randomPoints[i] < 0.3)
			countPointByDiapason[2]++;
		if (vector_randomPoints[i] >= 0.3 && vector_randomPoints[i] < 0.4)
			countPointByDiapason[3]++;
		if (vector_randomPoints[i] >= 0.4 && vector_randomPoints[i] < 0.5)
			countPointByDiapason[4]++;
		if (vector_randomPoints[i] >= 0.5 && vector_randomPoints[i] < 0.6)
			countPointByDiapason[5]++;
		if (vector_randomPoints[i] >= 0.6 && vector_randomPoints[i] < 0.7)
			countPointByDiapason[6]++;
		if (vector_randomPoints[i] >= 0.7 && vector_randomPoints[i] < 0.8)
			countPointByDiapason[7]++;
		if (vector_randomPoints[i] >= 0.8 && vector_randomPoints[i] < 0.9)
			countPointByDiapason[8]++;
		if (vector_randomPoints[i] >= 0.9 && vector_randomPoints[i] < 1.0)
			countPointByDiapason[9]++;
	}

	return countPointByDiapason;
}

function fillChart(countPointByDiapson,text)
{
    const point = x_vals.map((k, i) => ({x: k, y: countPointByDiapson[i]}));
    let data = {
        label: text,
        data:point,
        borderWidth: 1,
        barPercentage: 1,
        categoryPercentage: 1,
        backgroundColor: ['rgba(70, 205, 242, 0.2)',],
        borderColor: ['wheat'],
        // borderColor: [ 'rgba(252, 131, 143, 0.5)',],
        datalabels: {
            anchor: 'end',
            align: 'start',
            
          }
      };
    //console.log(point);
    //   const array = myChart.data.datasets.map((dataset,index) => 
    // {
    //     return dataset.label;
    // });
    // const position = array.indexOf(data.label); 
    myChart.data.datasets.splice(0,1);

    myChart.data.datasets.push(data);
    myChart.update();
}

  document.getElementById('btn_squareSegments').addEventListener('click', async function()
  {
    clearDataGrid();
    let countStep = document.getElementById('countPoint').value;
    if(countStep!=0)
    {
        let R0 = document.getElementById('defaultR0').value;
        let randomNumbers = methodOfMeanSquares(countStep,R0);
        let countPointByDiapson = countPointBySegment(randomNumbers);

        let expectedVal = expectedValue(randomNumbers);
        let dispers = dispersion(randomNumbers,expectedVal);
        let standartDev = standardDeviation(dispers);

        fillDataGridExtra('method0', expectedVal, dispers, standartDev);

		fillChart(countPointByDiapson,'Метод серединных отрезков');
		fillIntervalLabel(0, expectedVal, dispers, standartDev);

    }else
    {
        alert("Count step = 0!");
    }
  });

document.getElementById('btn_mult').addEventListener('click', async function()
  {
    clearDataGrid();
    let countStep = document.getElementById('countPoint').value;
    if(countStep!=0)
    {
        let R0 = document.getElementById('defaultR0').value;
        let R1 = document.getElementById('defaultR1_divisor').value;
        let randomNumbers = methodOfMult(countStep,R0,R1);
        let countPointByDiapson = countPointBySegment(randomNumbers);

        let expectedVal = expectedValue(randomNumbers);
        let dispers = dispersion(randomNumbers,expectedVal);
        let standartDev = standardDeviation(dispers);

        fillDataGridExtra('method1', expectedVal, dispers, standartDev);

		fillChart(countPointByDiapson,'Метод произведений');
		fillIntervalLabel(1, expectedVal, dispers, standartDev);

    }else
    {
        alert("Count step = 0!");
    }
  });
document.getElementById('btn_linearCongruent').addEventListener('click', async function()
  {
    clearDataGrid();
    let countStep = document.getElementById('countPoint').value;
    if(countStep!=0)
    {
        let R0 = document.getElementById('defaultR0').value;
        let divisor = document.getElementById('defaultR1_divisor').value;
        let randomNumbers = methodLinearCongruent(countStep,R0,divisor);
        let countPointByDiapson = countPointBySegment(randomNumbers);

        let expectedVal = expectedValue(randomNumbers);
        let dispers = dispersion(randomNumbers,expectedVal);
        let standartDev = standardDeviation(dispers);

        fillDataGridExtra('method2', expectedVal, dispers, standartDev);

		fillChart(countPointByDiapson,'Метод линейный конгруэтный');
	    fillIntervalLabel(2, expectedVal, dispers, standartDev);

    }else
    {
        alert("Count step = 0!");
    }
  });

  function methodLinearCongruentMixed(countPoints,multiplier,divisor,a)
  {
    let randNumb = new Array();
	let temp = multiplier;
	for (let i = 0; i < countPoints; i++)
	{
		let R3 = multiplier * temp + a;
		 if(i<10)
		 	fillDataGrid(temp, R3, R3%divisor);
		randNumb.push((R3%divisor) / 10000.0);
       // console.log(`temp = ${temp}, R3 =${R3}, R3%div = ${R3%divisor}`);
		temp = R3 % divisor;
        
	}
	return randNumb;
  }

  document.getElementById('btn_linearMixedCongruent').addEventListener('click', async function()
  {
    clearDataGrid();
    let countStep = document.getElementById('countPoint').value;
    if(countStep!=0)
    {
        let R0 = document.getElementById('defaultR0').value;
        let divisor = document.getElementById('defaultR1_divisor').value;
        let randomNumbers = methodLinearCongruentMixed(countStep,R0,divisor,1);
        let countPointByDiapson = countPointBySegment(randomNumbers);

        let expectedVal = expectedValue(randomNumbers);
        let dispers = dispersion(randomNumbers,expectedVal);
        let standartDev = standardDeviation(dispers);

        fillDataGridExtra('method2', expectedVal, dispers, standartDev);

		fillChart(countPointByDiapson,'Метод линейный конгруэтный');
	    fillIntervalLabel(2, expectedVal, dispers, standartDev);

    }else
    {
        alert("Count step = 0!");
    }
  });